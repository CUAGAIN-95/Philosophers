/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:35:23 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/18 17:07:38 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*check_one_die(void *temp_philo)
{
	t_philo		*philo;

	philo = (t_philo *)temp_philo;
	while (g_state != DIED && philo->state != ONE_FULL)
	{
		usleep(100);
		if (ft_get_time() - philo->time_stamp->eating > \
				philo->data.time_to_die)
		{
			pthread_mutex_lock(&g_state_mutex);
			message(" died\n", philo);
			g_state = DIED;
			pthread_mutex_unlock(&g_state_mutex);
			break ;
		}
	}
	return (NULL);
}

void	*check_all_full(void *temp_philo)
{
	t_philo_one	*philo_one;

	philo_one = (t_philo_one *)temp_philo;
	while (g_state != DIED && g_state != ALL_FULL)
	{
		if (g_count_full_philos == philo_one->num_of_philos)
		{
			pthread_mutex_lock(&g_state_mutex);
			message("All philo_onesophers are full!\n", NULL);
			g_state = ALL_FULL;
			pthread_mutex_unlock(&g_state_mutex);
			return (NULL);
		}
	}
	return (NULL);
}
