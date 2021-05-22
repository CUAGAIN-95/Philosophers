/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:09:20 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:50:13 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*check_all_full(void *arg)
{
	t_philo_two	*philo_two;

	philo_two = (t_philo_two*)arg;
	while (g_state != DIED && g_state != ALL_FULL)
	{
		if (g_count_full_philos == philo_two->num_of_philos)
		{
			sem_wait(&g_state);
			g_state = ALL_FULL;
			write(1, "ALL FULL!!\n", 11);
			sem_post(&g_state);
			return (NULL);
		}
	}
	return (NULL);
}

void	*check_one_die(void *arg)
{
	t_philo		*philo;

	philo = (t_philo*)arg;
	while (g_state != DIED && philo->state != ONE_FULL)
	{
		usleep(100);
		if (ft_get_time() - philo->time_stamp->eating > philo->data.time_to_die)
		{
			message("die...", philo);
			sem_wait(g_state_sem);
			g_state = DIED;
			sem_post(g_state_sem);
			return (NULL);
		}
	}
	return (NULL);
}
