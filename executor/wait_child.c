/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:45:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 18:52:47 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	wait_child(void)
{
	int	status;
	int	signo;

	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT)
				ft_putstr_fd("^C\n", STDERR_FILENO);
			else if (signo == SIGQUIT)
				ft_putstr_fd("^\\Quit: 3\n", STDERR_FILENO);
			g_exit_code = 128 + signo;
		}
		else
			g_exit_code = WEXITSTATUS(status);
	}
}
