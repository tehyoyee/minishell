/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:19:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:50:00 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static int	check_valid_unset_syntax(int argc, char *argv[])
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (++i < argc)
	{
		if (argv[i] == NULL)
		{
			print_err3("unset", "", "not a valid identifier");
			return (-1);
		}
		if (is_contain_this_char(argv[i], '='))
			ret = -1;
		else if (is_contain_space(argv[i], '\0'))
			ret = -1;
		else if (is_all_digit(argv[i], '\0'))
			ret = -1;
		if (ret == -1)
		{
			print_err3("unset", "", "not a valid identifier");
			return (ret);
		}
	}
	return (0);
}

static void	remove_env(t_env *env)
{
	t_env	*next;
	t_env	*prev;

	next = env->next;
	prev = env->prev;
	prev->next = next;
	next->prev = prev;
	free(env->key);
	free(env->value);
	free(env);
}

static void	doing_unset(t_env *env_head, char *key)
{
	t_env	*env;

	env = compare_env_key(env_head, key);
	if (env->key == NULL)
		return ;
	else
		remove_env(env);
}

int	ft_unset(int argc, char *argv[], t_env *env_head)
{
	int	i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (check_valid_unset_syntax(argc, argv) == -1)
		return (EXIT_FAILURE);
	i = 0;
	while (++i < argc)
		doing_unset(env_head, argv[i]);
	return (EXIT_SUCCESS);
}
