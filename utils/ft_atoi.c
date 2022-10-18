/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:41:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/07 18:41:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str++ - '0');
		if (ret < 0)
			return ((sign + 1) / -2);
	}
	return (sign * ret);
}
