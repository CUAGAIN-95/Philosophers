/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:33:53 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/10 09:56:49 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_free(t_data *data, int result)
{
	if (!data)
		free(data);
	while (1)
		;
	return (result);
}

int			init_data(t_data *data, int argc, char **argv)
{
	int		i;

	if (!(data = (t_data *)malloc(sizeof(data))))
		return (KO);
	i = ft_atoi(argv[1]);
	data->number_of_philosophers = i;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = 0;
	return (OK);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 5 && argc != 6)
		return (0);
	if (!init_data(data, argc, argv))
		return (ft_free(data, KO));
	
	return (ft_free(data, OK));
}