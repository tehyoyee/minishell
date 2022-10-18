/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:08:49 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/12 16:15:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static int	is_op_n(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strncmp(str, "-n", 2))
		return (0);
	str++;
	while (*str && *str == 'n')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

static int	check_op(int argc, char *argv[], int *idx)
{
	int	i;
	int	op_n;

	i = 1;
	if (argc == 1)
		return (0);
	op_n = is_op_n(argv[i]);
	while (i < argc && is_op_n(argv[i]))
		i++;
	*idx = i;
	return (op_n);
}

int	ft_echo(int argc, char *argv[])
{
	int	idx;
	int	op_n;

	idx = 1;
	op_n = check_op(argc, argv, &idx);
	while (idx < argc && argv[idx])
	{
		ft_write(STDOUT_FILENO, argv[idx], ft_strlen(argv[idx]));
		if (idx + 1 != argc)
			ft_write(STDOUT_FILENO, " ", 1);
		idx++;
	}
	if (op_n == 0)
		ft_write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
