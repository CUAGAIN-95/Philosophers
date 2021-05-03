/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:18:04 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:20:27 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	pthread_mutex_lock(philo->m_right_fork);
	message(" has taken a fork\n", philo);
	message(" has taken a fork\n", philo);
	philo->last_eat = ft_get_time();
	pthread_mutex_lock(&philo->mutex->m_num_of_full);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->mutex->m_num_of_full);
	if (philo->num_of_eat == philo->data->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->mutex->m_state);
		philo->state = FULL;
		philo->data->num_of_full++;
		pthread_mutex_unlock(&philo->mutex->m_state);
	}
	message(" is eating\n", philo);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->m_right_fork);
	pthread_mutex_unlock(philo->m_left_fork);
}

void	ft_sleeping(t_philo *philo)
{
	message(" is sleeping\n", philo);
	usleep(philo->data->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	message(" is thinking\n", philo);
}
