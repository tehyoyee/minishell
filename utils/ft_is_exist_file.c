/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_exist_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:37:25 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/30 18:38:53 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_is_exist_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	else
		return (1);
}
