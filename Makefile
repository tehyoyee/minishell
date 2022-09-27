# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 09:36:50 by taehykim          #+#    #+#              #
#    Updated: 2022/03/30 19:56:38 by taehykim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
# CFLAGS = -Wall -Wextra -Werror -I/Users/taehykim/.brew/opt/readline/include
CFLAGS = -I/Users/taehykim/.brew/opt/readline/include
LDFLAGS = -L/Users/taehykim/.brew/opt/readline/lib -lreadline
RM = rm -f
AR = ar
CRS = crs
INC_DIR = includes
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, main.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -I $(INC_DIR) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(LDFLAGS) -o $@ $(OBJS)
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re