/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:43:59 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/06 17:44:01 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*add_redir_space(char *str, char *line)
{
	if (*(line) == '<')
	{
		line--;
		if (!(*line == '<') && !is_space(*line))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -74);
		line++;
		if (!(*line == '<') && !is_space(*line))
			str = ft_strjoin_char(str, ' ');
	}
	else if (*(line) == '>')
	{
		line--;
		if (!(*line == '>') && !is_space(*line))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -76);
		line++;
		if (!(*line == '>') && !is_space(*line))
			str = ft_strjoin_char(str, ' ');
	}
	return (str);
}

char	*init_next_cmd(char *str, t_cmd **cmd, t_cmd *next, int *pipe)
{
	if (*pipe)
		exit_with_error("pipe error", "||", 1);
	(*cmd)->is_pipe = true;
	(*cmd)->argv = ft_split_cmd(str, ' ', &(*cmd)->argc);
	next = cmd_init();
	(*cmd)->next = next;
	next->prev = *cmd;
	(*cmd) = next;
	free(str);
	str = NULL;
	*pipe = 1;
	return (str);
}

char	*parse_cmd(char *str, char *line, int quotes_status, int *pipe)
{
	if (!quotes_status && is_space(*line))
		str = ft_strjoin_char(str, ' ');
	else if (quotes_status != 0 && *line == ' ')
		str = ft_strjoin_char(str, -32);
	else if (!quotes_status && (*line == '<' || *line == '>'))
		str = add_redir_space(str, line);
	else
	{
		str = ft_strjoin_char(str, *line);
		*pipe = 0;
	}
	return (str);
}

void	parse(char *line, t_cmd *cmd)
{
	t_cmd	*next;
	char	*str;
	int		pipe;
	int		quotes_status;

	next = NULL;
	str = NULL;
	quotes_status = 0;
	pipe = 0;
	while (*line)
	{
		quotes_status = get_quotes_status(quotes_status, *line, cmd);
		if (!quotes_status && *line == '|')
			str = init_next_cmd(str, &cmd, next, &pipe);
		else
			str = parse_cmd(str, line, quotes_status, &pipe);
		line++;
	}
	if (quotes_status)
		exit_with_error("quotes error", NULL, 1);
	if (str)
	{
		cmd->argv = ft_split_cmd(str, ' ', &(cmd->argc));
		free(str);
	}
}
