/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:22:49 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 01:58:39 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	philo->time_stamp->taken_fork = ft_get_time();
	message(" has taken a fork\n", philo);
	pthread_mutex_lock(philo->m_right_fork);
	philo->time_stamp->taken_fork = ft_get_time();
	message(" has taken a fork\n", philo);
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->m_left_fork);
	pthread_mutex_unlock(philo->m_right_fork);
}
