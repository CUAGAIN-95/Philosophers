/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:38:09 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:35:59 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*change_state_to_one_die(void *arg)
{
	t_philo			*philo;

	philo = (t_philo*)arg;
	sem_wait(g_state_sem);
	g_state = DIED;
	return (NULL);
}

void	*check_all_full(void *arg)
{
	t_philo_three	*philo_three;
	int				num_of_full;

	philo_three = (t_philo_three*)arg;
	num_of_full = 0;
	while (g_state != DIED && g_state != ALL_FULL)
	{
		sem_wait(g_all_full);
		num_of_full++;
		if (num_of_full == philo_three->num_of_philos)
		{
			g_state = ALL_FULL;
			sem_post(g_state_sem);
			sem_post(g_someone_die);
			sem_wait(g_write_sem);
			write(1, "All full!!\n", 11);
			sem_post(g_write_sem);
			return (NULL);
		}
	}
	return (NULL);
}

void	*kill_child(void *arg)
{
	t_philo			*philo;

	philo = (t_philo*)arg;
	sem_wait(g_someone_die);
	philo->state = DIED;
	sem_post(g_someone_die);
	return (NULL);
}

void	*check_one_die(void *arg)
{
	t_philo			*philo;

	philo = (t_philo*)arg;
	while (philo->state != DIED && philo->state != ONE_FULL)
	{
		usleep(100);
		if (ft_get_time() - philo->time_stamp->eating > \
				philo->data.time_to_die)
		{
			write_str("die...", philo);
			philo->state = DIED;
			sem_post(g_state_sem);
			sem_post(g_all_full);
			break ;
		}
	}
	return (NULL);
}
