/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:59:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 18:34:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_write(int fd, const void *buf, size_t byte)
{
	int	ret;

	ret = write(fd, buf, byte);
	if (ret == -1)
		exit_with_error("write()", strerror(errno), EXIT_FAILURE);
	return (ret);
}

void	*ft_malloc(size_t size, size_t n)
{
	void	*ret;

	ret = malloc(size * n);
	if (ret == NULL)
		exit_with_error("malloc()", strerror(errno), EXIT_FAILURE);
	return (ret);
}

char	*ft_getcwd(char *buf, size_t size)
{
	char	*pwd;

	pwd = getcwd(buf, size);
	if (pwd == NULL)
		exit_with_error("getcwd()", strerror(errno), EXIT_FAILURE);
	return (pwd);
}

void	ft_execve(const char *file, char *const *argv, char *const *envp)
{
	if (execve(file, argv, envp) == -1)
		exit_with_error("execve()", strerror(errno), 126);
}
