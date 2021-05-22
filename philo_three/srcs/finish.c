/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:02:45 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:52:22 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	unlink_sems(void)
{
	sem_unlink("forks");
	sem_unlink("pickup_forks");
	sem_unlink("write_sem");
	sem_unlink("state_sem");
	sem_unlink("all_full");
	sem_unlink("someone_die");
	sem_unlink("kill");
}

void	close_sem(void)
{
	sem_close(g_forks);
	sem_close(g_pickup_forks);
	sem_close(g_write_sem);
	sem_close(g_all_full);
	sem_close(g_state_sem);
	sem_close(g_someone_die);
	sem_close(g_kill);
}

void	free_all(t_philo_three *philo_three)
{
	int		i;

	i = 0;
	while (i < philo_three->num_of_philos)
	{
		if ((philo_three->philos + i)->time_stamp)
			free((philo_three->philos + i)->time_stamp);
		i++;
	}
	if (philo_three->philos)
		free(philo_three->philos);
}

int		ft_finish(t_philo_three *philo_three, const char *err_msg)
{
	unlink_sems();
	if (philo_three)
		free_all(philo_three);
	if (ft_strncmp(err_msg, "", 1))
		write(2, err_msg, ft_strlen(err_msg));
	return (OK);
}
