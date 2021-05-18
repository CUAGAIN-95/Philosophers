/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:05:14 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 02:05:14 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		set_data(t_data *data, int argc, char **argv)
{
	if ((data->time_to_die = (uint64_t)ft_atoi(argv[2])) < 0 || \
		(data->time_to_eat = (uint64_t)ft_atoi(argv[3])) < 0 || \
		(data->time_to_sleep = (uint64_t)ft_atoi(argv[4])) < 0)
		return (KO);
	if (argc == 6)
	{
		if ((data->num_of_must_eat = ft_atoi(argv[5])) < 0)
			return (0);
	}
	else
		data->num_of_must_eat = 0;
	return (OK);
}

int		init_time_stamp(t_time_stamp **time_stamp)
{
	if (!(*time_stamp = (t_time_stamp*)malloc(sizeof(t_time_stamp))))
		return (KO);
	(*time_stamp)->thinking = 0;
	(*time_stamp)->eating = 0;
	(*time_stamp)->sleeping = 0;
	(*time_stamp)->taken_first_fork = 0;
	(*time_stamp)->taken_second_fork = 0;
	return (OK);
}

int		set_one_philo(t_philo *philo, int name, int argc, char **argv)
{
	philo->philo_name = name;
	philo->num_of_eat = 0;
	philo->state = ALIVE;
	if (!set_data(&(philo->data), argc, argv))
		return (KO);
	if (!init_time_stamp(&(philo->time_stamp)))
		return (KO);
	return (OK);
}

int		init_philos(t_philo_two *philo_two, int argc, char **argv)
{
	int		i;

	if (!(philo_two->philos = \
		(t_philo *)malloc(sizeof(t_philo) * (philo_two->num_of_philos))))
		return (KO);
	i = 0;
	while (i < philo_two ->num_of_philos)
	{
		if (!set_one_philo(philo_two->philos + i, i + 1, argc, argv))
			return (KO);
		i++;
	}
	return (OK);
}

int		init_philo_two(t_philo_two *philo_two, int argc, char **argv)
{
	if ((philo_two->num_of_philos = ft_atoi(argv[1])) < 2)
		return (KO);
	if (!init_philos(philo_two, argc, argv))
		return (KO);
	return (OK);
}