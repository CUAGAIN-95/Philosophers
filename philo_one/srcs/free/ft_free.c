/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:00:15 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/16 13:39:23 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_free_data(t_data *data, int result)
{
	if (!data)
		free(data);
	return (result);
}

int				ft_free_mutex(t_mutex *mutex, int result)
{
	if (!mutex)
	{
		free(mutex);
	}
	return (result);
}

int				ft_free_philo(t_philo *philo, int result)
{
	if (!philo)
		free(philo);
	return (result);
}

int		ft_free_all(t_data *data, t_mutex *mutex, t_philo *philo, int result)
{
	ft_free_data(data, result);
	ft_free_mutex(mutex, result);
	ft_free_philo(philo, result);
	return (result);
}