/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:39 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/10 16:43:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"
# include "utils.h"
# include "shell_cmd.h"

/* argc_checker.c
***********************************************************************/
void	argc_checker(t_cmd **cmd);

/* ft_split_cmd.c
***********************************************************************/
char	**ft_split_cmd(char const *s, char c, int *argc);

/* ft_strjoin_char.c
***********************************************************************/
char	*ft_strjoin_char(char *str, char c);

/* ft_strjoin_free.c
***********************************************************************/
char	*ft_strjoin_free(char *s1, char *s2);

/* parse.c
***********************************************************************/
void	parse(char *line, t_cmd *cmd);

/* replace2.c
***********************************************************************/
int		get_quotes_status(int quotes_status, char c, t_cmd *cmd);
int		is_space(char c);
void	flush_argv(t_cmd *cmd, int *i);
void	argv_change(t_cmd *cmd, char *new_cmd, int i);
int		check_dollar(char c);

/* replace.c
***********************************************************************/
void	replace(t_cmd *cmd, t_env *head);
int		ft_isalnum(int c);

#endif
