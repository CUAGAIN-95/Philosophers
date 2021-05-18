/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:29:29 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/16 10:17:08 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	destroy_mutexes(t_philo_one *philo_one)
{
	int		i;

	pthread_mutex_destroy(&g_state_mutex);
	pthread_mutex_destroy(&g_message_mutex);
	i = 0;
	while (i < philo_one->num_of_philos)
	{
		pthread_mutex_destroy(philo_one->philos[i].m_left_fork);
		i++;
	}
}

static void	free_all(t_philo_one *philo_one)
{
	int		i;

	i = 0;
	while (i < philo_one->num_of_philos)
	{
		if (philo_one->philos[i].m_left_fork)
			free(philo_one->philos[i].m_left_fork);
		if (philo_one->philos[i].time_stamp)
			free(philo_one->philos[i].time_stamp);
		i++;
	}
	if (philo_one->philos)
		free(philo_one->philos);
}

int			ft_finish(t_philo_one *philo_one, const char *message)
{
	if (philo_one)
	{
		destroy_mutexes(philo_one);
		free_all(philo_one);
	}
	if (ft_strncmp(message, "", 1))
		write(2, message, ft_strlen(message));
	return (1);
}