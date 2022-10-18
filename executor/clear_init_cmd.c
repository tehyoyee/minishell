/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_init_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:21 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:14:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	clear_cmd(t_cmd *cmd_head)
{
	t_cmd	*cur;

	cur = cmd_head;
	while (cur)
	{
		if (cur->fd[READ] > 0)
			ft_close(cur->fd[READ]);
		if (cur->infile > 0)
			ft_close(cur->infile);
		if (cur->outfile > 0)
			ft_close(cur->outfile);
		if (cur->cmd_path != NULL)
			cur->cmd_path = ft_free(cur->cmd_path);
		cur = cur->next;
	}
	delete_tmp_file();
}

int	init_heredoc(t_cmd *cmd)
{
	t_cmd	*cur;

	cur = cmd;
	while (cur)
	{
		if (heredoc(cur) == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}
