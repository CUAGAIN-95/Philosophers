/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:33:53 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/26 20:36:58 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*ft_dining(void *temp_philo)
{
	pthread_t	died;
	t_philo		*philo;

	philo = temp_philo;
	pthread_create(&died, NULL, &is_died, (void *)philo);
	pthread_detach(died);
	if (philo->philo_name % 2 != 0)
		usleep(philo->data->time_to_eat);
	while (g_state != DIED && g_state != FULL)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

int			ft_philo_one(t_philo *philo)
{
	pthread_t	full;
	int			i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_dining, &philo[i]) < 0)
			return (KO);
		i++;
	}
	pthread_create(&full, NULL, &is_full, (void *)philo);
	pthread_detach(full);
	i = 0;
	while (i < philo->data->num_of_philo)
		pthread_join(philo[i++].thread, NULL);
	return (OK);
}

int			main(int argc, char **argv)
{
	t_data	data;
	t_mutex	mutex;
	t_philo	*philo;

	philo = NULL;
	if (argc != 5 && argc != 6)
		return (std_message("argument error\n", 2));
	if (!(init_data(&data, argc, argv)))
		return (std_message("argument error\n", 2));
	if (!init_mutex(&data, &mutex))
		return (std_message("mutex_create error\n", 2));
	if (!(philo = init_philo(&data, &mutex)))
		return (std_message("philo_create error\n", 2));
	if (!ft_philo_one(philo))
		return (KO);	//
	//
	return (OK);
}