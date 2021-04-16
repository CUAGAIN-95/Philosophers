/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:33:53 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/16 13:35:23 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*t_function(void *string)
{
	printf("%s\n", (char *)(string));
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	*data;
	t_mutex	*mutex;
	t_philo	*philo;

	data = NULL;
	mutex = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (0);
	if (!(data = init_data(argc, argv)))
		return (ft_free_all(data, mutex, philo, KO));
	if (!(mutex = init_mutex(data)))
		return (ft_free_all(data, mutex, philo, KO));
	if (!(mutex = init_mutex(data)))
		return (ft_free_all(data, mutex, philo, KO));
	return (ft_free_all(data, mutex, philo, OK));
}