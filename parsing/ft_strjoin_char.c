/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:31:46 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/07 12:12:35 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_strjoin_char(char *str, char c)
{
	size_t	len;
	char	*arr;
	size_t	i;
	char	*temp;

	temp = str;
	if (!str && !c)
		return (NULL);
	if (!str)
		return (ft_strdup(&c));
	len = ft_strlen(str) + 1;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		exit_with_error("malloc fail", strerror(errno), EXIT_FAILURE);
	i = 0;
	while (*str)
		arr[i++] = *str++;
	arr[i++] = c;
	arr[i] = '\0';
	free(temp);
	return (arr);
}
