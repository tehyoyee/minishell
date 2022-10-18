/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:13:37 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 22:00:26 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

char	*ft_getenv(t_env *env, char *key)
{
	t_env	*cur;

	cur = compare_env_key(env, key);
	return (cur->value);
}
