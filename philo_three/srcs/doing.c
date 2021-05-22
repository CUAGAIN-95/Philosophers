/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:30:00 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:52:46 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		thinking(t_philo *philo)
{
	philo->time_stamp->thinking = ft_get_time();
	write_str("is thinking", philo);
}

void		eating(t_philo *philo)
{
	philo->num_of_eat++;
	philo->time_stamp->eating = ft_get_time();
	write_str("is eating", philo);
	if (philo->num_of_eat == philo->data.num_of_must_eat)
	{
		philo->state = ONE_FULL;
		sem_post(g_all_full);
	}
	usleep(philo->data.time_to_eat * 1000);
}

void		sleeping(t_philo *philo)
{
	philo->time_stamp->sleeping = ft_get_time();
	write_str("is sleeping", philo);
	usleep(philo->data.time_to_sleep * 1000);
}

void		dining(void *arg)
{
	t_philo		*philo;
	pthread_t	check_one_die_tid;
	pthread_t	kill_child_tid;

	philo = (t_philo*)arg;
	pthread_create(&check_one_die_tid, NULL, check_one_die, (void*)philo);
	pthread_detach(check_one_die_tid);
	pthread_create(&kill_child_tid, NULL, kill_child, (void*)philo);
	pthread_detach(kill_child_tid);
	while (g_state != DIED && \
			philo->state != DIED && philo->state != ONE_FULL)
	{
		thinking(philo);
		pick_up_forks(philo);
		eating(philo);
		put_down_forks();
		sleeping(philo);
	}
}
