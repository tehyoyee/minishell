/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:22:46 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:50:50 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	os_builtins(t_cmd *cmd, t_env *env, char *envp[])
{
	char	*env_path;

	env_path = ft_getenv(env, "PATH");
	if (env_path == NULL && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (env_path != NULL && ft_strlen(env_path) == 0 && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "command not found");
		return (127);
	}
	ft_execve(cmd->cmd_path, cmd->argv, envp);
	return (EXIT_SUCCESS);
}

static int	execute_cmd(t_cmd *cmd, t_env *env, char *envp[])
{
	restore_redir_char(cmd);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd->argc, cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(env, cmd->argv[1]));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(cmd->argc, cmd->argv, env));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(cmd->argc, cmd->argv, env));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(env));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(cmd));
	return (os_builtins(cmd, env, envp));
}

static void	do_fork_cmd(t_cmd *cmd, t_env *env, char *envp[])
{
	pid_t	pid;
	int		exit_code;

	set_signal(DFL, DFL);
	pid = ft_fork();
	if (pid == 0)
	{
		redirect(cmd);
		close_unused_fd(cmd, pid);
		exit_code = execute_cmd(cmd, env, envp);
		exit(exit_code);
	}
	else
	{
		close_unused_fd(cmd, pid);
		set_signal(IGN, IGN);
	}
}

static void	do_cmd(t_cmd *cmd, t_env *env, char *envp[])
{
	g_exit_code = execute_cmd(cmd, env, envp);
	close_unused_fd(cmd, 1);
}

void	executor(t_cmd *cmd_head, t_env *env_head, char *envp[])
{
	t_cmd	*cur;

	cur = cmd_head;
	if (is_valid_cmd(cur) == -1)
		return (clear_cmd(cur));
	if (init_heredoc(cur) == -1)
		return (clear_cmd(cur));
	while (cur)
	{
		if (io_file_open(cur, env_head) == -1)
		{
			cur = cur->next;
			continue ;
		}
		if (is_need_fork(cur))
			do_fork_cmd(cur, env_head, envp);
		else
			do_cmd(cur, env_head, envp);
		cur = cur->next;
	}
	wait_child();
	set_signal(SHE, SHE);
	return (clear_cmd(cmd_head));
}
