/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:09:14 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:30:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_CMD_H
# define SHELL_CMD_H

# include "utils.h"
# include "struct.h"

/* env_util.c
***********************************************************************/
char	*get_env_key(char *path);
char	*get_env_value(char *path);
t_env	*compare_env_key(t_env *env, char *key);
t_env	*new_env(char *path);

/* ft_cd_util.c
***********************************************************************/
char	*concat_with_pwd(const char *key);
void	export_pwd(t_env *env, const char *pwd);

/* ft_cd .c
***********************************************************************/
int		ft_cd(t_env *env, char *path);

/* ft_echo.c
***********************************************************************/
int		ft_echo(int argc, char *argv[]);

/* ft_env.c
***********************************************************************/
int		ft_env(t_env *cur);

/* ft_exit.c
***********************************************************************/
int		ft_exit(t_cmd *cmd);

/* ft_export_only_util.c
***********************************************************************/
t_env	*dup_env_list(t_env *cur);
t_env	*sort_env_list(t_env *env_head);
void	free_env_list(t_env *env);

/* ft_export_util.c
***********************************************************************/
int		is_all_digit(char *src, char set);
int		is_contain_space(char *src, char set);
int		is_contain_this_char(char *src, char c);
int		check_valid_export(int argc, char *argv[]);

/* ft_export.c
***********************************************************************/
void	export_key_value(t_env *env, char *path);
int		ft_export(int argc, char *argv[], t_env *env_head);

/* ft_getenv.c
***********************************************************************/
char	*ft_getenv(t_env *env, char *key);

/* ft_pwd.c
***********************************************************************/
int		ft_pwd(void);

/* ft_unset.c
***********************************************************************/
int		ft_unset(int argc, char *argv[], t_env *env_head);

#endif