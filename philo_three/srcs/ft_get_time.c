/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:01:34 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:51:14 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

uint64_t		ft_get_time(void)
{
	struct timeval	time;
	uint64_t		result;

	if (gettimeofday(&time, NULL))
		return (KO);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}
