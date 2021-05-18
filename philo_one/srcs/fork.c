<<<<<<< HEAD:philo_one/srcs/fork.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:22:49 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/17 20:15:10 by yeonhlee         ###   ########.fr       */
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
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:24 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:39:01 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_destroy(t_philo *philo)
{
    (void)philo;
}
>>>>>>> 8d63dfb349480c4263ad98f27eee065eb8e8796b:philo_one/srcs/free/ft_destroy.c
