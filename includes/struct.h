/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:14:01 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:31:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include <stdbool.h>

int	g_exit_code;

typedef struct s_cmd
{
	char			**argv;
	int				argc;
	bool			is_pipe;
	bool			is_dollar;
	int				fd[2];
	int				infile;
	int				outfile;
	char			*cmd_path;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

/* cmd_init.c
***********************************************************************/
void	*ft_free(void *ptr);
t_cmd	*cmd_init(void);
int		init_env_list(t_env *cur, char **envp);

#endif