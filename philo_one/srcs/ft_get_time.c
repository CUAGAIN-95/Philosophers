/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:01:34 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/10 11:17:52 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

uint64_t		ft_get_time(void)
{
	struct timeval	time;
	uint64_t			result;

	if (gettimeofday(&time, NULL))
		return (KO);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}
