/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:19:00 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:52:56 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_child_process(t_philo_three *philo_three)
{
	int			i;
	t_philo		*philos;

	waitpid(-1, NULL, 0);
	i = 0;
	philos = philo_three->philos;
	while (i < philo_three->num_of_philos)
	{
		kill(philos[i].pid, SIGTERM);
		i++;
	}
}

int		make_check_full_threads(t_philo_three *philo_three)
{
	pthread_t	check_all_full_tid;
	pthread_t	kill_all_full_tid;

	if (philo_three->philos->data.num_of_must_eat > 0)
	{
		if (pthread_create(&check_all_full_tid, NULL, check_all_full, \
							(void*)philo_three))
			return (KO);
		if (pthread_create(&kill_all_full_tid, NULL, change_state_to_one_die, \
							(void*)philo_three))
			return (KO);
		pthread_join(check_all_full_tid, NULL);
		pthread_join(kill_all_full_tid, NULL);
	}
	return (OK);
}

int		create_process(t_philo_three *philo_three)
{
	int			i;
	uint64_t	start_time;

	i = 0;
	start_time = ft_get_time();
	while (i < philo_three->num_of_philos)
	{
		philo_three->philos[i].time_stamp->start_time = start_time;
		philo_three->philos[i].time_stamp->eating = start_time;
		if ((philo_three->philos[i].pid = fork()) == 0)
		{
			dining((void*)(philo_three->philos + i));
			exit(0);
		}
		else if (philo_three->philos[i].pid == -1)
			return (KO);
		i++;
	}
	if (!make_check_full_threads(philo_three))
	{
		kill_child_process(philo_three);
		return (KO);
	}
	kill_child_process(philo_three);
	return (OK);
}
