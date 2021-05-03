/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:09:11 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/03 17:47:32 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->m_message);
	if (g_state != DIED && g_state != FULL)
	{
		printf("%ld ms ", ft_get_time() - philo->data->start_time);
		printf("%d", philo->philo_name);
		printf("%s", str);
	}
	pthread_mutex_unlock(&philo->mutex->m_message);
}

int		end_message(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	if (fd == 2)
		return (KO);
	return (OK);
}
