/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:35:23 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/26 20:31:41 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*is_died(void *temp_philo)
{
	t_philo	*philo;

	philo = (t_philo *)temp_philo;
	while(g_state != DIED && g_state != FULL)	
	{
		if (ft_get_time() - philo->last_eat > philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->mutex->m_state);
			message(" is died\n", philo);
			philo->state = DIED;
			g_state = DIED;
			pthread_mutex_unlock(&philo->mutex->m_state);
			break ;
		}
	}
	// printf("%d g_state : %d\n",philo->philo_name, g_state);
	printf("die......\n");
	return (NULL);
}

void	*is_full(void *temp_philo)
{
	t_philo	*philo;

	philo = (t_philo *)temp_philo;
	while (g_state != DIED && g_state != FULL)
	{
		if (philo->data->num_of_full == philo->data->num_of_philo)
		{
			pthread_mutex_lock(&philo->mutex->m_state);
			printf("All philosophers are full!\n");
			g_state = FULL;
			pthread_mutex_unlock(&philo->mutex->m_state);
			break ;
		}
	}
	printf("full......\n");
	return (NULL);
}