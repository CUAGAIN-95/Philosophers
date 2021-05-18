/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:38:56 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 00:06:58 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		create_threads(t_philo_two *philo_two)
{
	int			i;
	t_philo		*philos;
	uint64_t	start_time;
	pthread_t	check_all_full_tid;

	i = 0;
	philos = philo_two->philos;
	start_time = ft_get_time();
	if (philos[0].data.num_of_must_eat > 0)
	{
		if (pthread_create(&check_all_full_tid, NULL, \
							check_all_full, (void*)philo_two))
			return (KO);
		pthread_detach(check_all_full_tid);
	}
	while (i < philo_two->num_of_philos)
	{
		philos[i].time_stamp->start_time = start_time;
		philos[i].time_stamp->eating = start_time;
		if (pthread_create(&(philos[i].tid), NULL, dining, (void*)(philos + i)))
			return (KO);
		i++;
	}
	return (OK);
}

int		join_threads(t_philo_two philo_two)
{
	int			i;
	t_philo		*philos;

	i = 0;
	philos = philo_two.philos;
	while (i < philo_two.num_of_philos)
	{
		if (pthread_join(philos[i].tid, NULL))
			return (KO);
		i++;
	}
	return (OK);
}
