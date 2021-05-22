/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:32:10 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 21:08:43 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		init_global_variables(int num_of_forks)
{
	g_state = ALIVE;
	unlink_sems();
	if ((g_forks = sem_open("forks", O_CREAT, 0644, num_of_forks)) \
			== SEM_FAILED || \
		(g_pickup_forks = sem_open("pickup_forks", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_write_sem = sem_open("write_sem", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_all_full = sem_open("all_full", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_state_sem = sem_open("state_sem", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_someone_die = sem_open("someone_die", O_CREAT, 0644, 1)) \
			== SEM_FAILED || \
		(g_kill = sem_open("kill", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (KO);
	sem_wait(g_all_full);
	sem_wait(g_state_sem);
	sem_wait(g_someone_die);
	return (OK);
}

int		main(int argc, char **argv)
{
	t_philo_three	philo_three;

	if (!check_argument(argc, argv))
		return (ft_finish(NULL, "argument error\n"));
	if (!init_philo_three(&philo_three, argc, argv))
		return (ft_finish(&philo_three, "init philo_three error\n"));
	if (!init_global_variables(philo_three.num_of_philos))
		return (ft_finish(&philo_three, "init global variables error\n"));
	if (!create_process(&philo_three))
		return (ft_finish(&philo_three, "create process error\n"));
	close_sem();
	ft_finish(&philo_three, "");
	return (OK);
}
