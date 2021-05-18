/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:24:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 01:31:36 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	close_sem(void)
{
	sem_close(g_forks);
	sem_close(g_pickup_forks);
	sem_close(g_message_sem);
	sem_close(g_state_sem);
}

void	free_all(t_philo_two *philo_two)
{
	int	i;

	i = 0;
	while (i < philo_two->num_of_philos)
	{
		if ((philo_two->philos + i)->time_stamp)
			free((philo_two->philos + i)->time_stamp);
		i++;
	}
	if (philo_two->philos)
		free(philo_two->philos);
}

int		ft_finish(t_philo_two *philo_two, const char **err_msg)
{
	if (philo_two)
		free_all(philo_two);
	if (ft_strncmp(err_msg, "", 1))
		write(2, err_msg, ft_strlen(err_msg));
	return (1);
}	