/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:38:40 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:21:44 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	pick_up_forks(t_philo *philo)
{
	sem_wait(g_pickup_forks);
	sem_wait(g_forks);
	philo->time_stamp->taken_first_fork = ft_get_time();
	write_str("taken first fork", philo);
	sem_post(g_forks);
	philo->time_stamp->taken_second_fork = ft_get_time();
	write_str("taken second fork", philo);
	sem_post(g_pickup_forks);
}

void	put_down_forks(void)
{
	sem_post(g_forks);
	sem_post(g_forks);
}