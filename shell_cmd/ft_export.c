/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:06:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 21:48:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static void	append_env(t_env *env, char *key, char *value)
{
	t_env	*new;

	new = new_env(NULL);
	new->prev = env;
	env->next = new;
	env->key = key;
	env->value = value;
}

static void	change_env_value(t_env *env, char *key, char *value)
{
	free(env->value);
	free(key);
	env->value = value;
}

void	export_key_value(t_env *env_cmd, char *path)
{
	t_env	*env;
	char	*key;
	char	*value;

	key = get_env_key(path);
	value = get_env_value(path);
	env = compare_env_key(env_cmd, key);
	if (env->key == NULL)
		append_env(env, key, value);
	else
		change_env_value(env, key, value);
}

static int	ft_export_only(t_env *env_head)
{
	t_env	*tmp;
	t_env	*sorted_env;
	t_env	*cur;

	tmp = dup_env_list(env_head);
	sorted_env = sort_env_list(tmp);
	cur = sorted_env;
	while (cur->key)
	{
		ft_write(STDOUT_FILENO, "declare -x ", 11);
		ft_write(STDOUT_FILENO, cur->key, ft_strlen(cur->key));
		ft_write(STDOUT_FILENO, "=\"", 2);
		ft_write(STDOUT_FILENO, cur->value, ft_strlen(cur->value));
		ft_write(STDOUT_FILENO, "\"\n", 2);
		cur = cur->next;
	}
	free_env_list(sorted_env);
	return (EXIT_SUCCESS);
}

int	ft_export(int argc, char *argv[], t_env *env_head)
{
	int	i;
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (check_valid_export(argc, argv) == -1)
		exit_code = EXIT_FAILURE;
	else if (argc == 1)
		exit_code = ft_export_only(env_head);
	else
	{
		i = 0;
		while (++i < argc)
			export_key_value(env_head, argv[i]);
	}
	return (exit_code);
}
