/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:44:17 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/14 18:18:27 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*key_to_value(char str, char *new_cmd, t_env *head, int quotes)
{
	static char	*key = NULL;

	if (ft_isalnum(str) || str == '_')
		key = ft_strjoin_char(key, str);
	else if (str == '?' && key == NULL)
	{
		key = ft_itoa(g_exit_code);
		new_cmd = ft_strjoin_free(new_cmd, key);
		key = ft_free(key);
	}
	else
	{
		if (key != NULL)
		{
			new_cmd = ft_strjoin_free(new_cmd, ft_getenv(head, key));
			if ((str == '\'' && quotes == 2) || (str == '"' && quotes == 1))
				new_cmd = ft_strjoin_char(new_cmd, str);
			key = ft_free(key);
			g_exit_code = 0;
		}
		else
			new_cmd = ft_strjoin_char(new_cmd, '$');
	}
	return (new_cmd);
}

static char	*get_replaced_cmd_else(char c, char *new_cmd, int quotes)
{
	char	*result;

	result = NULL;
	if (c == -32)
		result = ft_strjoin_char(new_cmd, ' ');
	else if (!(c == '\"' && quotes != 1) && !(c == '\'' && quotes != 2))
		result = ft_strjoin_char(new_cmd, c);
	else if (c == '\'' && quotes == 3)
		result = ft_strjoin_char(new_cmd, c);
	else
		return (new_cmd);
	return (result);
}

static char	*get_replaced_cmd(t_cmd *cmd, t_env *head, int i)
{
	int		j;
	char	*new_cmd;
	int		dollar;
	int		quotes;

	quotes = 0;
	dollar = 0;
	j = 0;
	new_cmd = NULL;
	while (j <= (int)ft_strlen(cmd->argv[i]))
	{
		quotes = get_quotes_status(quotes, cmd->argv[i][j], cmd);
		if (cmd->argv[i][j] == '$' && quotes != 1 && dollar == 0 \
									&& cmd->argv[i][j + 1] != '\'')
			dollar = 1;
		else if (dollar == 1)
		{
			new_cmd = key_to_value(cmd->argv[i][j], new_cmd, head, quotes);
			dollar = check_dollar(cmd->argv[i][j]);
		}
		else
			new_cmd = get_replaced_cmd_else(cmd->argv[i][j], new_cmd, quotes);
		j++;
	}
	return (new_cmd);
}

void	replace(t_cmd *cmd, t_env *head)
{
	int		i;
	char	*new_cmd;

	while (cmd)
	{
		i = 0;
		while (i < cmd->argc)
		{
			new_cmd = get_replaced_cmd(cmd, head, i);
			if (new_cmd == NULL && cmd->is_dollar)
				flush_argv(cmd, &i);
			else if (new_cmd == NULL)
			{
				new_cmd = ft_strdup("");
				argv_change(cmd, new_cmd, i);
			}
			else
				argv_change(cmd, new_cmd, i);
			i++;
		}
		cmd = cmd->next;
	}
}
