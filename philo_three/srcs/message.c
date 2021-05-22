/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:49:46 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 16:16:51 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	write_str(char *str, t_philo *philo)
{
	sem_wait(g_write_sem);
	if (philo->state != DIED && philo->state != ONE_FULL)
	{
		printf("%llums\t", ft_get_time() - philo->time_stamp->start_time);
		printf("%d %s", philo->philo_name, str);
		if (!ft_strncmp(str, "is eating", 10))
			printf("\t\t%d\n", philo->num_of_eat);
		else
			printf("\n");
		if (!ft_strncmp(str, "die...", 7))
		{
			sem_post(g_someone_die);
			usleep(100);
		}
	}
	sem_post(g_write_sem);
}
