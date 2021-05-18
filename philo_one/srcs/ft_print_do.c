/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:09:11 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/18 17:08:08 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&g_message_mutex);
	if (philo == NULL)
		printf("%s", str);
	else if (g_state != DIED && philo->state != ONE_FULL)
	{
		printf("%llu ms ", ft_get_time() - philo->time_stamp->start_time);
		printf("%d", philo->philo_name);
		printf("%s", str);
	}
	pthread_mutex_unlock(&g_message_mutex);
}
