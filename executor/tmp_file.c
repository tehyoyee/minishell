/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:04:48 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:25:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	get_tmp_file_num(void)
{
	static int	tmp_file_num;

	return (tmp_file_num++);
}

char	*get_tmp_file_name(void)
{
	char	*file_name;
	char	*str_num;

	while (1)
	{
		str_num = ft_itoa(get_tmp_file_num());
		file_name = ft_strjoin("tmp_file_", str_num);
		if (ft_is_exist_file(file_name) == 0)
		{
			free(str_num);
			return (file_name);
		}
		free(file_name);
		free(str_num);
	}
}

void	delete_tmp_file(void)
{
	char	*str_num;
	char	*tmp_filename;
	int		tmp_num;

	tmp_num = get_tmp_file_num();
	while (--tmp_num >= 0)
	{
		str_num = ft_itoa(tmp_num);
		tmp_filename = ft_strjoin("tmp_file_", str_num);
		if (ft_is_exist_file(tmp_filename))
			unlink(tmp_filename);
		free(str_num);
		free(tmp_filename);
	}
}
