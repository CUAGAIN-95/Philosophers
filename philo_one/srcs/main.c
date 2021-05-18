/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:33:53 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/18 17:44:01 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_global_variables(void)
{
	g_state = ALIVE;
	g_count_full_philos = 0;
	if (pthread_mutex_init(&g_state_mutex, NULL))
		return (KO);
	if (pthread_mutex_init(&g_message_mutex, NULL))
		return (KO);
	return (OK);
}

int			main(int argc, char **argv)
{
	t_philo_one		philo_one;

	if (!check_argument(argc, argv))
		return (ft_finish(NULL, "argument error\n"));
	if (!init_global_variables())
		return (ft_finish(NULL,"mutex create error"));
	if (!init_philo_one(&philo_one, argc, argv))
		return (ft_finish(&philo_one, "init philo_one error\n"));
	if (!create_threads(&philo_one))
		return (ft_finish(&philo_one, "create thread error\n"));
	if (!join_threads(philo_one))
		return (ft_finish(&philo_one, "joining threads error!\n"));
	ft_finish(&philo_one, "");
	return (OK);
}
