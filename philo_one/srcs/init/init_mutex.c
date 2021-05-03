/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:21 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:19:02 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			init_mutex(t_data *data, t_mutex *mutex)
{
	int		i;

	if (!(mutex->m_forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo)))
		return (KO);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&(mutex->m_forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&mutex->m_message, NULL);
	pthread_mutex_init(&mutex->m_state, NULL);
	pthread_mutex_init(&mutex->m_num_of_full, NULL);
	return (OK);
}
