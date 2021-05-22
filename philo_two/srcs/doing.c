/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:08:00 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:50:01 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	thinking(t_philo *philo)
{
	philo->time_stamp->thinking = ft_get_time();
	message("is thinking", philo);
}

void	eating(t_philo *philo)
{
	if (g_state != DIED && philo->state != ONE_FULL)
		philo->num_of_eat++;
	philo->time_stamp->eating = ft_get_time();
	message("is eating", philo);
	if (philo->num_of_eat == philo->data.num_of_must_eat)
	{
		sem_wait(g_state_sem);
		philo->state = ONE_FULL;
		g_count_full_philos++;
		sem_post(g_state_sem);
	}
	usleep(philo->data.time_to_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	philo->time_stamp->sleeping = ft_get_time();
	message("is sleeping", philo);
	usleep(philo->data.time_to_sleep * 1000);
}

void	*dining(void *arg)
{
	t_philo		*philo;
	pthread_t	check_one_die_tid;

	philo = (t_philo*)arg;
	if (pthread_create(&check_one_die_tid, NULL, check_one_die, (void*)philo))
		return (NULL);
	pthread_detach(check_one_die_tid);
	while (g_state != DIED && philo->state != ONE_FULL)
	{
		thinking(philo);
		pick_up_forks(philo);
		eating(philo);
		put_down_forks();
		sleeping(philo);
	}
	return (NULL);
}
