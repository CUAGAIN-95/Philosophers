/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:18:04 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:47:43 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	thinking(t_philo *philo)
{
	philo->time_stamp->thinking = ft_get_time();
	message(" is thinking\n", philo);
}

void	eating(t_philo *philo)
{
	philo->num_of_eat++;
	philo->time_stamp->eating = ft_get_time();
	message(" is eating\n", philo);
	if (philo->num_of_eat == philo->data.num_of_must_eat)
	{
		pthread_mutex_lock(&g_state_mutex);
		philo->state = ONE_FULL;
		g_count_full_philos++;
		pthread_mutex_unlock(&g_state_mutex);
	}
	usleep(philo->data.time_to_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	philo->time_stamp->sleeping = ft_get_time();
	message(" is sleeping\n", philo);
	usleep(philo->data.time_to_sleep * 1000);
}

void	*dining(void *arg)
{
	t_philo		*philo;
	pthread_t	check_one_die_tid;

	philo = (t_philo *)arg;
	if (pthread_create(&check_one_die_tid, NULL, check_one_die, (void*)philo))
		return (NULL);
	pthread_detach(check_one_die_tid);
	if (philo->philo_name % 2)
		usleep(philo->data.time_to_eat * 1000);
	while (g_state != DIED && philo->state != ONE_FULL)
	{
		thinking(philo);
		pick_up_forks(philo);
		eating(philo);
		put_down_forks(philo);
		sleeping(philo);
	}
	return (NULL);
}
