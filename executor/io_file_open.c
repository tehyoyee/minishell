/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:43:14 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:51:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	infile_open(t_cmd *cmd)
{
	const char	redir_in[2] = {-74, '\0'};
	int			i;

	while (1)
	{
		i = -1;
		while (cmd->argv[++i])
			if (!ft_strcmp(cmd->argv[i], redir_in))
				break ;
		if (cmd->argv[i] == NULL)
			break ;
		if (cmd->infile > 0)
			ft_close(cmd->infile);
		cmd->infile = open(cmd->argv[i + 1], O_RDONLY, 0644);
		if (cmd->infile == -2)
			print_err3(cmd->argv[i + 1], NULL, "No such file or directory");
		trim_cmd_argv(cmd, redir_in, 2);
	}
}

static void	outfile_open(t_cmd *cmd)
{
	const char	r_o[2] = {-76, '\0'};
	const char	r_a[3] = {-76, -76, '\0'};
	int			i;

	while (1)
	{
		i = -1;
		while (cmd->argv[++i])
			if (!ft_strcmp(cmd->argv[i], r_o) || !ft_strcmp(cmd->argv[i], r_a))
				break ;
		if (cmd->argv[i] == NULL)
			break ;
		if (cmd->outfile > 0)
			ft_close(cmd->outfile);
		outfile_open_cmd_with_trim(cmd, i);
	}
}

int	io_file_open(t_cmd *cmd, t_env *env_head)
{
	ft_pipe(cmd->fd);
	infile_open(cmd);
	if (cmd->infile == -1)
	{
		g_exit_code = EXIT_FAILURE;
		return (-1);
	}
	outfile_open(cmd);
	cmd->cmd_path = get_cmd_path(cmd, env_head);
	return (0);
}
