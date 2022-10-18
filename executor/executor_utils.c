/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:11:13 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/02 19:06:09 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	restore_redir_char(t_cmd *cmd)
{
	int	i;
	int	j;

	i = -1;
	while (cmd->argv[++i])
	{
		j = -1;
		while (cmd->argv[i][++j])
		{
			if (cmd->argv[i][j] == -74)
				cmd->argv[i][j] = '<';
			else if (cmd->argv[i][j] == -76)
				cmd->argv[i][j] = '>';
		}
	}
}

int	is_need_fork(t_cmd *cmd)
{
	if (cmd->prev != NULL)
		return (1);
	if (cmd->is_pipe == true)
		return (1);
	if (cmd->infile != -2)
		return (1);
	if (cmd->outfile != -2)
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (0);
	return (1);
}
