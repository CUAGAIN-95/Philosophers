/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:22 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:48:19 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		check_all_full_thread(t_philo_one *philo_one)
{
	pthread_t	check_all_full_tid;

	if (philo_one->philos[0].data.num_of_must_eat > 0)
	{
		if (pthread_create(&check_all_full_tid, NULL, check_all_full, \
							(void *)philo_one))
			return (KO);
		pthread_detach(check_all_full_tid);
	}
	return (OK);
}

int				create_threads(t_philo_one *philo_one)
{
	int			i;

	i = 0;
	while (i < philo_one->num_of_philos)
	{
		philo_one->philos[i].time_stamp->start_time = ft_get_time();
		philo_one->philos[i].time_stamp->eating = ft_get_time();
		if (pthread_create(&(philo_one->philos[i].tid), NULL, dining, \
							(void *)(philo_one->philos + i)))
			return (KO);
		i++;
	}
	if (!check_all_full_thread(philo_one))
		return (KO);
	return (OK);
}

int				join_threads(t_philo_one philo_one)
{
	int			i;

	i = 0;
	while (i < philo_one.num_of_philos)
	{
		if (pthread_join(philo_one.philos[i].tid, NULL))
			return (KO);
		i++;
	}
	return (OK);
}
