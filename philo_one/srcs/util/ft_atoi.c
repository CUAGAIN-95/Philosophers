/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:51:49 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:22:40 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	long	i;
	long	result;
	int		minus;

	i = 0;
	result = 0;
	minus = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nptr[i] != '\0' && '0' <= nptr[i] && nptr[i] <= '9')
	{
		result = (result * 10) + (int)(nptr[i] - '0');
		i++;
	}
	return ((int)(result * minus));
}
