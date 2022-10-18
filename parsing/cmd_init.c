/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:39:24 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/29 18:40:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

t_cmd	*cmd_init(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->argc = 0;
	new_cmd->argv = NULL;
	new_cmd->is_dollar = false;
	new_cmd->fd[0] = -2;
	new_cmd->fd[1] = -2;
	new_cmd->infile = -2;
	new_cmd->outfile = -2;
	new_cmd->cmd_path = NULL;
	new_cmd->is_pipe = false;
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return (new_cmd);
}
