/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:07 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:22:02 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo		*init_philo(t_data *data, t_mutex *mutex)
{
	t_philo	*philo;
	int		i;

	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo)))
		return (KO);
	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].philo_name = i + 1;
		philo[i].data = data;
		philo[i].mutex = mutex;
		philo[i].m_left_fork = &mutex->m_forks[i];
		if (i == data->num_of_philo - 1)
			philo[i].m_right_fork = &mutex->m_forks[0];
		else
			philo[i].m_right_fork = &mutex->m_forks[i + 1];
		philo[i].last_eat = ft_get_time();
		philo[i].num_of_eat = 0;
		philo[i].state = ALIVE;
		i++;
	}
	return (philo);
}
