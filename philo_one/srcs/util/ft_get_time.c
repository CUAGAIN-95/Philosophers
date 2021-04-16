/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:01:34 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/14 22:02:39 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

double		ft_get_time(void)
{
	struct timeval	start;
	double			result;

	if (gettimeofday(&start, NULL))
		return (KO);
	result = start.tv_sec + start.tv_usec / 1000000.0;
	printf("현재 시간 %f\n", result);				//
	return (result);
}