/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:20:29 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/06 19:20:30 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	flush_argv(t_cmd *cmd, int *i)
{
	int		tmp;

	tmp = *i;
	cmd->argv[tmp] = ft_free(cmd->argv[tmp]);
	while (tmp < cmd->argc - 1)
	{
		cmd->argv[tmp] = cmd->argv[tmp + 1];
		tmp++;
	}
	*i = *i - 1;
	cmd->argc = cmd->argc - 1;
	cmd->is_dollar = false;
	cmd->argv[tmp] = 0;
}

void	argv_change(t_cmd *cmd, char *new_cmd, int i)
{
	cmd->argv[i] = ft_free(cmd->argv[i]);
	cmd->argv[i] = new_cmd;
}

int	check_dollar(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '$')
		return (1);
	else
		return (0);
}
