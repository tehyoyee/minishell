/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:21 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/14 18:17:13 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_free(t_cmd *cmd)
{
	t_cmd	*cmd_temp;
	int		i;

	while (cmd)
	{
		i = -1;
		while (++i < cmd->argc)
			free(cmd->argv[i]);
		free(cmd->argv);
		cmd_temp = cmd;
		if (!cmd->next)
		{
			free(cmd);
			break ;
		}
		cmd = cmd->next;
		free(cmd_temp);
	}
}

void	main_init(int argc, char *argv[])
{
	struct termios	term;

	if (argc != 1)
		exit_with_error("input argument error", NULL, 126);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	set_signal(SHE, SHE);
	g_exit_code = 0;
	(void)argc;
	(void)argv;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	t_env	env;
	char	*line;

	main_init(argc, argv);
	init_env_list(&env, envp);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break ;
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			cmd = cmd_init();
			parse(line, cmd);
			replace(cmd, &env);
			argc_checker(&cmd);
			executor(cmd, &env, envp);
			cmd_free(cmd);
		}
		free(line);
	}
}
