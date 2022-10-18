/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:31:46 by taehykim          #+#    #+#             */
/*   Updated: 2022/10/13 19:49:57 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len;
	char	*arr;
	size_t	i;
	char	*temp;

	temp = s1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		exit_with_error("malloc fail", strerror(errno), EXIT_FAILURE);
	i = 0;
	while (*s1)
		arr[i++] = *s1++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	free(temp);
	return (arr);
}
