/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:29:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/01 17:09:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_with_error(char *str1, char *str2, int code)
{
	ft_putstr_fd("minishell : ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	if (str2)
	{
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putstr_fd(str2, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(code);
}

void	print_err(char *str)
{
	ft_putstr_fd("minishell : ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_err2(char *str1, char *str2)
{
	ft_putstr_fd("minishell : ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_err3(char *cmd, char *str1, char *str2)
{
	ft_putstr_fd("minishell : ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	if (str1)
	{
		ft_putstr_fd(str1, STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
	}
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
