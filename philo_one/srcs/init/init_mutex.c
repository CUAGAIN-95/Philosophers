/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:21 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/16 13:40:55 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_mutex		*init_mutex(t_data *data)
{
	t_mutex *mutex;

	if (!(mutex = (t_mutex *)malloc(sizeof(t_mutex))))
		return (KO);
	mutex->num_of_philo = data->num_of_philo;
	if (!(mutex->m_forks = 
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * mutex->num_of_philo)))
		return (KO);
	return (mutex);
}