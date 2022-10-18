/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:37:30 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/13 20:54:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

static char	*get_absolute_path(t_cmd *cmd, char *env_path)
{
	char	*ret;
	char	*slash_cmd;
	char	**path;
	int		i;

	path = ft_split(env_path, ':');
	slash_cmd = ft_strjoin("/", cmd->argv[0]);
	i = -1;
	while (path[++i])
	{
		ret = ft_strjoin(path[i], slash_cmd);
		if (ft_is_exist_file(ret))
			break ;
		free(ret);
	}
	free(slash_cmd);
	if (path[i] == NULL)
		ret = NULL;
	free_path(path);
	return (ret);
}

char	*get_cmd_path(t_cmd *cmd, t_env *env_head)
{
	char	*ret;
	char	*env_path;

	ret = NULL;
	env_path = ft_getenv(env_head, "PATH");
	if (env_path != NULL)
		ret = get_absolute_path(cmd, env_path);
	if (ret == NULL && ft_is_exist_file(cmd->argv[0]))
		return (ft_strdup(cmd->argv[0]));
	return (ret);
}
