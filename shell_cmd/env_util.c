/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:15:37 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/08 14:14:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

char	*get_env_key(char *path)
{
	size_t	i;
	size_t	len;
	char	*key;

	len = 0;
	while (path[len] != 0 && path[len] != '=')
		len++;
	if (path[len] == '\0')
		return (NULL);
	key = (char *)malloc(sizeof(len + 1));
	i = -1;
	while (++i < len)
		key[i] = path[i];
	key[i] = 0;
	return (key);
}

char	*get_env_value(char *path)
{
	size_t	i;
	size_t	len;
	char	*value;

	len = 0;
	while (path[len] != 0 && path[len] != '=')
		path++;
	if (path[len] == 0)
		return (NULL);
	len = ft_strlen(++path);
	value = (char *)ft_malloc(sizeof(char), len + 1);
	i = 0;
	while (i < len)
	{
		value[i] = path[i];
		i++;
	}
	value[i] = 0;
	return (value);
}

t_env	*compare_env_key(t_env *env, char *key)
{
	t_env	*cur;

	cur = env;
	while (cur->key != 0 && ft_strncmp(key, cur->key, ft_strlen(cur->key)))
		cur = cur->next;
	return (cur);
}

t_env	*new_env(char *path)
{
	t_env	*new;

	new = (t_env *)ft_malloc(sizeof(t_env), 1);
	if (path == NULL)
	{
		new->key = NULL;
		new->value = NULL;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->key = get_env_key(path);
		new->value = get_env_value(path);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

int	init_env_list(t_env *cur, char **envp)
{
	size_t	i;
	t_env	*new;

	i = 0;
	cur->key = get_env_key(envp[i]);
	cur->value = get_env_value(envp[i]);
	cur->next = NULL;
	cur->prev = NULL;
	while (envp[++i])
	{
		new = new_env(envp[i]);
		if (!new)
			return (-1);
		new->prev = cur;
		cur->next = new;
		cur = new;
	}
	new = new_env(NULL);
	new->prev = cur;
	cur->next = new;
	return (0);
}
