/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:31:16 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 13:33:19 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_write(STDOUT_FILENO, pwd, ft_strlen(pwd));
	ft_write(STDOUT_FILENO, "\n", 1);
	free(pwd);
	return (EXIT_SUCCESS);
}
