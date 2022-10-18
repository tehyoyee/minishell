/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:22:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:27:27 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "utils.h"
# include "struct.h"
# include "shell_cmd.h"

# define READ 0
# define WRITE 1

/* clear_init_cmd.c
***********************************************************************/
void	clear_cmd(t_cmd *cmd_head);
int		init_heredoc(t_cmd *cmd);

/* close_unused_fd.c
***********************************************************************/
void	close_unused_fd(t_cmd *cmd, pid_t pid);

/* executor_utils.c
***********************************************************************/
void	restore_redir_char(t_cmd *cmd);
int		is_need_fork(t_cmd *cmd);

/* executor .c
***********************************************************************/
void	executor(t_cmd *cmd_head, t_env *env_head, char *envp[]);

/* heredoc .c
***********************************************************************/
int		heredoc(t_cmd *cmd_head);

/* io_file_open .c
***********************************************************************/
int		io_file_open(t_cmd *cmd, t_env *env_head);

/* is_valid_cmd .c
***********************************************************************/
int		is_valid_cmd(t_cmd *cmd_head);

/* path .c
***********************************************************************/
char	*get_cmd_path(t_cmd *cmd, t_env *env_head);

/* redirect .c
***********************************************************************/
void	redirect(t_cmd *cmd);

/* tmp_file .c
***********************************************************************/
char	*get_tmp_file_name(void);
void	delete_tmp_file(void);

/* trim_cmd_argv .c
***********************************************************************/
void	trim_cmd_argv(t_cmd *cmd, const char *set, int size);
void	outfile_open_cmd_with_trim(t_cmd *cmd, int i);

/* wait_child .c
***********************************************************************/
void	wait_child(void);
#endif