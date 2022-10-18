# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 09:36:50 by taehykim          #+#    #+#              #
#    Updated: 2022/10/14 18:17:38 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
READLINE_INC = -I/Users/taehykim/.brew/opt/readline/include
READLINE_LIB = -L/Users/taehykim/.brew/opt/readline/lib -lreadline

# READLINE_INC = -I/Users/wonjchoi/.brew/opt/readline/include
# READLINE_LIB = -L/Users/wonjchoi/.brew/opt/readline/lib -lreadline

RM = rm -f
AR = ar
CRS = crs
INC_DIR = includes
UTIL_DIR = utils
EXEC_DIR = executor
STRC_DIR = struct
SCMD_DIR = shell_cmd
PARSING_DIR = parsing

SRCS = main.c \
		$(addprefix $(EXEC_DIR)/, \
		clear_init_cmd.c \
		close_unused_fd.c \
		executor_utils.c \
		executor.c \
		heredoc.c \
		io_file_open.c \
		is_valid_cmd.c \
		path.c \
		redirect.c \
		tmp_file.c \
		trim_cmd_argv.c \
		wait_child.c \
		)\
		$(addprefix $(UTIL_DIR)/, \
		ft_atoi.c \
		ft_exit_with_error.c \
		ft_is_exist_file.c \
		ft_is_whitespace.c \
		ft_isspace.c \
		ft_itoa.c\
		ft_putstr_fd.c \
		ft_signal.c \
		ft_split.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_system_util.c \
		ft_system_util2.c \
		)\
		$(addprefix $(SCMD_DIR)/, \
		env_util.c \
		ft_cd_util.c \
		ft_cd.c \
		ft_echo.c \
		ft_env.c \
		ft_exit.c \
		ft_export_only_util.c \
		ft_export_util.c \
		ft_export.c \
		ft_getenv.c \
		ft_pwd.c \
		ft_unset.c \
		)\
		$(addprefix $(PARSING_DIR)/, \
		parse.c \
		ft_strjoin_char.c \
		ft_split_cmd.c \
		replace.c \
		replace_2.c \
		parse_utils.c \
		ft_strjoin_free.c \
		argc_checker.c \
		quotes_status.c \
		cmd_init.c \
		)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(READLINE_INC) -c -I $(INC_DIR) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(LDFLAGS) $(READLINE_LIB) -o $@ $(OBJS)
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re