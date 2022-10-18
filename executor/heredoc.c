/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:38:40 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/02 19:00:31 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	check_heredoc(t_cmd *cmd)
{
	const char	redir_h[3] = {-74, -74, '\0'};
	int			i;

	i = -1;
	while (cmd->argv[++i])
		if (!ft_strcmp(cmd->argv[i], redir_h))
			break ;
	if (cmd->argv[i] == NULL)
		return (-1);
	return (i);
}

static void	input_heredoc(t_cmd *cmd, int lim_idx)
{
	char	*line;
	char	*limiter;

	limiter = cmd->argv[lim_idx];
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		else if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_write(cmd->infile, line, ft_strlen(line));
		ft_write(cmd->infile, "\n", 1);
		free(line);
	}
}

static int	wait_heredoc(pid_t pid)
{
	int	status;
	int	signo;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		signo = WTERMSIG(status);
		if (signo == SIGINT)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	fork_heredoc(t_cmd *cmd, int lim_idx)
{
	const char	redir_h[3] = {-74, -74, '\0'};
	pid_t		pid;
	int			ret;

	set_signal(DFL, SHE);
	pid = fork();
	if (pid == 0)
	{
		input_heredoc(cmd, lim_idx + 1);
		cmd->infile = ft_close(cmd->infile);
		exit(EXIT_SUCCESS);
	}
	else
	{
		set_signal(IGN, IGN);
		cmd->infile = ft_close(cmd->infile);
		ret = wait_heredoc(pid);
	}
	set_signal(SHE, SHE);
	trim_cmd_argv(cmd, redir_h, 2);
	return (ret);
}

int	heredoc(t_cmd *cmd_head)
{
	t_cmd	*cur;
	int		idx;
	char	*tmp_file;
	int		exit_code;

	while (1)
	{
		cur = cmd_head;
		idx = check_heredoc(cur);
		if (idx == -1)
			return (0);
		if (cur->infile > 0)
			ft_close(cur->infile);
		tmp_file = get_tmp_file_name();
		cur->infile = ft_open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		exit_code = fork_heredoc(cur, idx);
		g_exit_code = exit_code;
		if (exit_code == EXIT_SUCCESS)
			cur->infile = ft_open(tmp_file, O_RDONLY, 0664);
		free(tmp_file);
		if (exit_code == EXIT_FAILURE)
			return (-1);
	}
	return (exit_code);
}
