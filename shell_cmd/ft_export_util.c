/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:35:55 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:49:12 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

int	is_all_digit(char *src, char set)
{
	while (*src)
	{
		if (!ft_isdigit(*src))
			break ;
		src++;
	}
	if (*src == set)
		return (1);
	return (0);
}

int	is_contain_space(char *src, char set)
{
	while (*src && *src != set)
	{
		if (ft_isspace(*src))
			break ;
		src++;
	}
	if (*src == set)
		return (0);
	return (1);
}

int	is_contain_this_char(char *src, char c)
{
	while (*src)
	{
		if (*src == c)
			return (1);
		src++;
	}
	return (0);
}

int	check_valid_export(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_contain_this_char(argv[i], '='))
		{
			print_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_contain_space(argv[i], '='))
		{
			print_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_all_digit(argv[i], '='))
		{
			print_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
	}
	return (0);
}
