/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:49:46 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 01:42:36 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	message(char *str, t_philo *philo)
{
	sem_wait(g_message_sem);
	if (g_state != DIED && philo->state != ONE_FULL)
	{
		printf("%llums\t", ft_get_time() - philo->time_stamp->start_time);
		printf("%d %s", philo->philo_name, str);
		if (!ft_strncmp(str, "is eating", 10))
			printf("\t\t%d\n", philo->num_of_eat);
		else
			printf("\n");
	}
	sem_post(g_message_sem);
}