/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:38:53 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/02 19:00:24 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_unused_fd(t_cmd *cmd, pid_t pid)
{
	if (pid == 0)
	{
		if (cmd->fd[READ] != -2)
			cmd->fd[READ] = ft_close(cmd->fd[READ]);
	}
	else
	{
		if (cmd->fd[WRITE] != -2)
			cmd->fd[WRITE] = ft_close(cmd->fd[WRITE]);
	}
}
