/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:01:34 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/23 21:01:14 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long		ft_get_time(void)
{
	struct timeval	time;
	long			result;

	if (gettimeofday(&time, NULL))
		return (KO);
	result = time.tv_sec * (long)1000 + time.tv_usec / (long)1000;
	return (result);
}