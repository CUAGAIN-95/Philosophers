/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/16 13:40:40 by yeonhlee         ###   ########.fr       */
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

# define KO		0
# define OK		1

/*
** =============================================================================
**	struct
** =============================================================================
*/

typedef struct		s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	double			start_time;
}					t_data;

typedef struct		s_mutex
{
	pthread_mutex_t	*m_forks;
	int				num_of_philo;
}					t_mutex;


typedef struct		s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	t_mutex			*mutex;
	
	
}					t_philo;


/*
** =============================================================================
**	free.c
** =============================================================================
*/

int					ft_free_data(t_data *data, int result);
int					ft_free_mutex(t_mutex *mutex, int result);
int					ft_free_philo(t_philo *philo, int result);
int					ft_free_all(t_data *data, t_mutex *mutex, \
									t_philo *philo, int result);

/*
** =============================================================================
**	init.c
** =============================================================================
*/

t_data				*init_data(int argc, char **argv);
t_mutex				*init_mutex(t_data *data);
t_philo				*init_philo(t_data *data);

/*
** =============================================================================
**	util
** =============================================================================
*/

double				ft_get_time(void);

int					ft_atoi(const char *nptr);

#endif