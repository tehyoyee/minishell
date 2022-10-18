/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:51:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/03 18:00:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_close(int fd)
{
	if (close(fd) == -1)
		exit_with_error("close()", strerror(errno), EXIT_FAILURE);
	return (-2);
}

int	ft_open(char *filename, int flag, int mode)
{
	int	fd;

	fd = open(filename, flag, mode);
	if (fd < 0)
		exit_with_error("open()", strerror(errno), EXIT_FAILURE);
	return (fd);
}

void	ft_pipe(int *fds)
{
	if (pipe(fds) == -1)
		exit_with_error("pipe()", strerror(errno), EXIT_FAILURE);
}

pid_t	ft_fork(void)
{
	int	ret;

	ret = fork();
	if (ret < 0)
		exit_with_error("fork()", strerror(errno), EXIT_FAILURE);
	return (ret);
}

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit_with_error("dup2()", strerror(errno), EXIT_FAILURE);
}
