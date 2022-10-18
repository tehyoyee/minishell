/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:35:15 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 15:15:47 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

char	*concat_with_pwd(const char *key)
{
	char	*tmp;
	char	*result;

	tmp = ft_getcwd(NULL, 0);
	result = ft_strjoin(key, tmp);
	free(tmp);
	return (result);
}

void	export_pwd(t_env *env, const char *pwd)
{
	char	*tmp_pwd;

	tmp_pwd = concat_with_pwd(pwd);
	export_key_value(env, tmp_pwd);
	free(tmp_pwd);
}
