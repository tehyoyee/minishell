/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_only_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:41:26 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 21:48:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static t_env	*dup_env(t_env *env)
{
	t_env	*new;

	new = (t_env *)ft_malloc(sizeof(t_env), 1);
	if (env == NULL)
	{
		new->key = NULL;
		new->value = NULL;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->key = ft_strdup(env->key);
		new->value = ft_strdup(env->value);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_env	*dup_env_list(t_env *cur)
{
	t_env	*ret;
	t_env	*new;
	t_env	*tmp;

	ret = dup_env(cur);
	tmp = ret;
	cur = cur->next;
	while (cur->key)
	{
		new = dup_env(cur);
		tmp->next = new;
		new->prev = tmp;
		tmp = new;
		cur = cur->next;
	}
	new = dup_env(NULL);
	tmp->next = new;
	new->prev = tmp;
	return (ret);
}

static void	swap_env(t_env *e1, t_env *e2)
{
	char	*tmp_k;
	char	*tmp_v;

	tmp_k = e1->key;
	tmp_v = e1->value;
	e1->key = e2->key;
	e1->value = e2->value;
	e2->key = tmp_k;
	e2->value = tmp_v;
}

t_env	*sort_env_list(t_env *env_head)
{
	t_env	*cur;

	cur = env_head;
	while (cur->next->key)
	{
		if (ft_strcmp(cur->key, cur->next->key) > 0)
		{
			swap_env(cur, cur->next);
			cur = env_head;
		}
		else
			cur = cur->next;
	}
	return (env_head);
}

void	free_env_list(t_env *env)
{
	t_env	*next;

	while (env->key)
	{
		next = env->next;
		ft_free(env->key);
		ft_free(env->value);
		ft_free(env);
		env = next;
	}
	ft_free(env->key);
	ft_free(env->value);
	ft_free(env);
}
