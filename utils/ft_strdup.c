/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:05:19 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/01 14:05:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	while (s1[i])
		i++;
	arr = (char *)malloc(sizeof(char) * i + 1);
	if (!arr)
		exit_with_error("malloc fail ! ", strerror(errno), 1);
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		arr[i] = s1[i];
		i--;
	}
	return (arr);
}
