/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/10 09:56:55 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofdayf
# include <pthread.h>	// pthread_create, pthread_detach, pthread_join
						// pthread_mutex_init, pthread_mutex_destroy
						// pthread_mutex_lock, pthread_mutex_unlock

# define KO			0
# define OK			1

/*
** =============================================================================
**	struct
** =============================================================================
*/

typedef struct		s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	
}					t_data;

/*
** =============================================================================
**	util.c
** =============================================================================
*/

int					ft_atoi(const char *nptr);

#endif