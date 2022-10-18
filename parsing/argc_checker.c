/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:11:33 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 12:38:42 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	first(t_cmd *tmp, t_cmd **ptr, t_cmd **head_cmd)
{
	tmp = (*ptr)->next;
	tmp->prev = NULL;
	(*head_cmd)->argv = ft_free((*head_cmd)->argv);
	*head_cmd = ft_free((*head_cmd));
	*head_cmd = tmp;
	*ptr = tmp;
}

void	argc_checker(t_cmd **cmd)
{
	t_cmd	*ptr;
	t_cmd	*tmp;

	tmp = NULL;
	ptr = *cmd;
	while (ptr)
	{
		if (ptr->prev == NULL && ptr->next == NULL)
			return ;
		if (ptr->argc == 0 && ptr->prev == NULL)
			first(tmp, &ptr, cmd);
		else if (ptr->argc == 0)
		{
			tmp = ptr->next;
			tmp->next = ptr->next;
			ptr->argv = ft_free(ptr->argv);
			ptr = ft_free(ptr);
			ptr = tmp->next;
			if (ptr)
				ptr->prev = tmp;
		}
		else
			ptr = ptr->next;
	}
}
