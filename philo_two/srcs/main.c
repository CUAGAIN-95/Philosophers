/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:14:04 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 01:31:47 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		init_global_variables(int num_of_philos)
{
	g_state = ALIVE;
	g_count_full_philos = 0;
	sem_unlink("forks");
	sem_unlink("pickup_forks");
	sem_unlink("message_sem");
	sem_unlink("state_sem");
	if ((g_forks = sem_open("forks", O_CREAT, 0644, num_of_philos)) \
			== SEM_FAILED || \
		(g_pickup_forks = sem_open("pickup_forks", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_message_sem = sem_open("message_sem", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_state_sem = sem_open("state_sem", O_CREAT, 0644, 1)) \
			== SEM_FAILED)
		return (KO);
	return (OK);
}

int		main(int argc, char **argv)
{
	t_philo_two		philo_two;

	if (!check_argument(argc, argv))
		return (ft_finish(NULL, "argument error\n"));
	if (!init_philo_two(&philo_two, argc, argv))
		return (ft_finish(&philo_two, "init phio_two error\n"));
	if (!init_global_variables(philo_two.num_of_philos))
		return (ft_finish(&philo_two, "semaphore open error\n"));
	if (!create_threads(&philo_two))
		return (ft_finish(&philo_two, "create threads error\n"));
	if (!join_threads(philo_two))
		return (ft_finish(&philo_two, "join threads error\n"));
	close_sem();
	ft_finish(&philo_two, "");
	return (0);
}