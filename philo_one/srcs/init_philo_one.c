/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:07 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/16 11:10:12 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	set_data(t_data *data, int argc, char **argv)
{
	if ((data->time_to_die = (uint64_t)ft_atoi(argv[2])) < 0 || \
		(data->time_to_eat = (uint64_t)ft_atoi(argv[3])) < 0 || \
		(data->time_to_sleep = (uint64_t)ft_atoi(argv[4])) < 0)
		return (KO);
	if (argc == 6)
	{
		if ((data->num_of_must_eat = ft_atoi(argv[5])) < 0)
			return (KO);
	}
	else
		data->num_of_must_eat = 0;
	return (OK);
}

static int	init_time_stamp(t_time_stamp **time_stamp)
{
	if (!(*time_stamp = (t_time_stamp *)malloc(sizeof(t_time_stamp))))
		return (KO);
	(*time_stamp)->start_time = 0;
	(*time_stamp)->thinking = 0;
	(*time_stamp)->eating = 0;
	(*time_stamp)->sleeping = 0;
	(*time_stamp)->taken_fork = 0;
	return (OK);
}

static int	set_one_philo(t_philo *philo, int id, int argc, char **argv)
{
	philo->philo_name = id;
	philo->num_of_eat = 0;
	philo->state = ALIVE;
	if (!set_data(&(philo->data), argc, argv))
		return (KO);
	if (!init_time_stamp(&(philo->time_stamp)))
		return (KO);
	if (!(philo->m_left_fork = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (KO);
	if (pthread_mutex_init(philo->m_left_fork, NULL))
		return (KO);
	return (OK);
}

static int	init_philos(t_philo_one *philo_one, int argc, char **argv)
{
	int		i;

	if (!(philo_one->philos = \
		(t_philo *)malloc(sizeof(t_philo) * (philo_one->num_of_philos))))
		return (KO);
	i = 0;
	while (i < philo_one->num_of_philos)
	{
		if (!set_one_philo(philo_one->philos + i, i + 1, argc, argv))
			return (KO);
		i++;
	}
	i = 0;
	while (i < philo_one->num_of_philos)
	{
		philo_one->philos[i].m_right_fork = \
			philo_one->philos[(i + 1) % philo_one->num_of_philos].m_left_fork;
		i++;
	}
	return (OK);
}

int			init_philo_one(t_philo_one *philo_one, int argc, char **argv)
{
	if ((philo_one->num_of_philos = ft_atoi(argv[1])) < 2)
		return (KO);
	if (!init_philos(philo_one, argc, argv))
		return (KO);
	return (OK);
}
