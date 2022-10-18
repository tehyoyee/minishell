/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:25:19 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/12 16:48:31 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	trim_cmd_argv(t_cmd *cmd, const char *set, int size)
{
	int	i;
	int	tmp;
	int	tmp_argc;

	i = -1;
	tmp_argc = cmd->argc;
	while (++i < cmd->argc)
		if (!ft_strcmp(cmd->argv[i], set))
			break ;
	if (i == cmd->argc)
		return ;
	tmp = i;
	cmd->argc -= size;
	while (size--)
	{
		free(cmd->argv[i]);
		while (i < tmp_argc)
		{
			cmd->argv[i] = cmd->argv[i + 1];
			i++;
		}
		i = tmp;
	}
}

void	outfile_open_cmd_with_trim(t_cmd *cmd, int i)
{
	const char	r_o[2] = {-76, '\0'};
	const char	r_a[3] = {-76, -76, '\0'};
	int			o_flag;

	if (ft_strcmp(cmd->argv[i], r_o) == 0)
	{
		o_flag = O_WRONLY | O_CREAT | O_TRUNC;
		cmd->outfile = ft_open(cmd->argv[i + 1], o_flag, 0644);
		trim_cmd_argv(cmd, r_o, 2);
	}
	else if (ft_strcmp(cmd->argv[i], r_a) == 0)
	{
		o_flag = O_WRONLY | O_CREAT | O_APPEND;
		cmd->outfile = ft_open(cmd->argv[i + 1], o_flag, 0644);
		trim_cmd_argv(cmd, r_a, 2);
	}
}
