/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:29:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:35:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <readline/readline.h>
# include <fcntl.h>

# define SHE 0
# define DFL 1
# define IGN 2

/* ft_atoi.c
***********************************************************************/
int		ft_atoi(const char *str);

/* ft_exit_with_error.c
***********************************************************************/
void	exit_with_error(char *str1, char *str2, int code);
void	print_err(char *str);
void	print_err2(char *str1, char *str2);
void	print_err3(char *cmd, char *str1, char *str2);

/* ft_is_exist_file.c
***********************************************************************/
int		ft_is_exist_file(char *file_name);

/* ft_is_whitespace.c
***********************************************************************/
int		is_whitespace(char *line);

/* ft_isdigit.c
***********************************************************************/
int		ft_isdigit(int c);

/* ft_isspace.c
***********************************************************************/
int		ft_isspace(char c);

/* ft_itoa.c
***********************************************************************/
char	*ft_itoa(int n);

/* ft_putstr_fd.c
***********************************************************************/
void	ft_putstr_fd(char *s, int fd);

/* ft_signal.c
***********************************************************************/
void	set_signal(int sig_int, int sig_quit);

/* ft_split.c
***********************************************************************/
char	**ft_split(char const *s, char c);

/* ft_strcmp.c
***********************************************************************/
int		ft_strcmp(const char *s1, const char *s2);

/* ft_strdup.c
***********************************************************************/
char	*ft_strdup(const char *s1);

/* ft_strjoin.c
***********************************************************************/
char	*ft_strjoin(char const *s1, char const *s2);

/* ft_strlcpy.c
***********************************************************************/
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/* ft_strlen.c
***********************************************************************/
size_t	ft_strlen(const char *c);

/* ft_strncmp.c
***********************************************************************/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ft_system_util.c
***********************************************************************/
int		ft_close(int fd);
int		ft_open(char *filename, int flag, int mode);
void	ft_pipe(int *fds);
pid_t	ft_fork(void);
void	ft_dup2(int fd1, int fd2);

/* ft_system_util2.c
***********************************************************************/
int		ft_write(int fd, const void *buf, size_t byte);
void	*ft_malloc(size_t size, size_t n);
char	*ft_getcwd(char *buf, size_t size);
void	ft_execve(const char *file, char *const *argv, char *const *envp);

#endif