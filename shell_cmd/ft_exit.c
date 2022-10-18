/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:37 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:48:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static int	is_all_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	exit_only(t_cmd *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->prev == NULL)
		ft_write(STDOUT_FILENO, "exit\n", 5);
	exit(exit_code);
}

static void	exit_with_arg(t_cmd *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->prev == NULL)
		ft_write(STDOUT_FILENO, "exit\n", 5);
	if (!is_all_num(cmd->argv[1]))
	{
		print_err3("exit", cmd->argv[1], "numeric argument required");
		exit_code = 255;
	}
	else
		exit_code = ft_atoi(cmd->argv[1]) % 256;
	exit(exit_code);
}

int	ft_exit(t_cmd *cmd)
{
	if (cmd->argc == 1)
		exit_only(cmd);
	if (cmd->argc == 2)
		exit_with_arg(cmd);
	if (cmd->argc > 2)
		print_err3("exit", NULL, "too many arguments");
	return (EXIT_SUCCESS);
}
