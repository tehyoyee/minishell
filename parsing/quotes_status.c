/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:19:12 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:13 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_quotes_status_2(int quotes_status, char c)
{
	if (quotes_status == 3)
	{
		if (c == '\'')
			return (2);
		else if (c == '"')
			return (0);
		else
			return (3);
	}
	if (c == '"')
		return (2);
	else if (c == '\'')
		return (1);
	return (0);
}

int	get_quotes_status(int quotes_status, char c, t_cmd *cmd)
{
	if (c == '$')
		cmd->is_dollar = true;
	if (quotes_status == 1)
	{
		if (c == '\'')
			return (0);
		else
			return (1);
	}
	else if (quotes_status == 2)
	{
		if (c == '"')
			return (0);
		else if (c == '\'')
			return (3);
		else
			return (2);
	}
	else
		return (get_quotes_status_2(quotes_status, c));
}
