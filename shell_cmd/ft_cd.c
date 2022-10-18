/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:11:46 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:48:11 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_cmd.h"

static int	cd_home(t_env *env, char *path)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;

	exit_code = EXIT_FAILURE;
	home = ft_getenv(env, "HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = concat_with_pwd("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", path, strerror(errno));
		else
			export_key_value(env, tmp_pwd);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd(env, "PWD=");
	return (exit_code);
}

static int	cd_tilde(t_env *env)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = concat_with_pwd("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", home, strerror(errno));
		else
			export_key_value(env, tmp_pwd);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd(env, "PWD=");
	return (exit_code);
}

static int	cd_tilde_path(t_env *env, char *path)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;
	char	*hoem_path;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = concat_with_pwd("OLDPWD=");
		hoem_path = ft_strjoin(home, path + 1);
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", path, strerror(errno));
		else
			export_key_value(env, tmp_pwd);
		free(hoem_path);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd(env, "PWD=");
	return (exit_code);
}

static int	cd_path(t_env *env, char *path)
{
	char	*tmp_pwd;
	int		exit_code;

	exit_code = EXIT_FAILURE;
	tmp_pwd = concat_with_pwd("OLDPWD=");
	exit_code = chdir(path);
	if (exit_code == -1)
		print_err3("cd", path, strerror(errno));
	else
		export_key_value(env, tmp_pwd);
	free(tmp_pwd);
	if (exit_code != -1)
		export_pwd(env, "PWD=");
	return (exit_code);
}

int	ft_cd(t_env *env, char *path)
{
	if (path == NULL)
		return (cd_home(env, path));
	else if (!ft_strcmp("~", path))
		return (cd_tilde(env));
	else if (!ft_strncmp("~/", path, 2))
		return (cd_tilde_path(env, path));
	else
		return (cd_path(env, path));
}
