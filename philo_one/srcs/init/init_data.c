/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:56 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/27 17:51:28 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_data(t_data *data, int argc, char **argv)
{
	g_state = ALIVE;
	if ((data->num_of_philo = ft_atoi(argv[1])) == -1)
		return (KO);
	if ((data->time_to_die = ft_atoi(argv[2])) == -1)
		return (KO);
	if ((data->time_to_eat = ft_atoi(argv[3])) == -1)
		return (KO);
	if ((data->time_to_sleep = ft_atoi(argv[4])) == -1)
		return (KO);
	if (argc == 6 && (data->num_of_must_eat = ft_atoi(argv[5])) == -1)
		return (KO);
	else if (argc == 5)
		data->num_of_must_eat = -1;
	if (!(data->start_time = ft_get_time()))
		return (KO);
	data->num_of_full = 0;
	return (OK);
}
