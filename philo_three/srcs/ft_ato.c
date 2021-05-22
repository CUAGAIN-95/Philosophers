/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:51:49 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/21 15:21:29 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	while (nptr[i] != '\0')
	{
		result = (result * 10) + (int)(nptr[i] - '0');
		i++;
	}
	return ((int)(result * minus));
}

long		ft_atol(const char *nptr)
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
	while (nptr[i] != '\0')
	{
		result = (result * 10) + (int)(nptr[i] - '0');
		i++;
	}
	return (result * minus);
}
