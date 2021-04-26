/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/04/26 19:20:13 by yeonhlee         ###   ########.fr       */
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

# define DIED	0
# define ALIVE	1
# define FULL	2

int					g_state;

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
	long			start_time;
	int				num_of_full;
}					t_data;

typedef struct		s_mutex
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_message;
	pthread_mutex_t	m_state;
	pthread_mutex_t m_num_of_full;
}					t_mutex;


typedef struct		s_philo
{
	pthread_t		thread;
	int				philo_name;
	t_data			*data;
	t_mutex			*mutex;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	long			last_eat;
	int				num_of_eat;
	int				state;
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

int					init_data(t_data *data, int argc, char **argv);
int					init_mutex(t_data *data, t_mutex *mutex);
t_philo				*init_philo(t_data *data, t_mutex *mutex);

/*
** =============================================================================
**	util
** =============================================================================
*/

long				ft_get_time(void);
int					ft_atoi(const char *nptr);
int					ft_strlen(const char *str);

/*
** =============================================================================
**	doing.c
** =============================================================================
*/

void				ft_eating(t_philo *philo);
void				ft_sleeping(t_philo *philo);
void				ft_thinking(t_philo *philo);

/*
** =============================================================================
**	monitoring.c
** =============================================================================
*/

void				*is_died(void *temp_philo);
void				*is_full(void *temp_philo);


/*
** =============================================================================
**	ft_print_do.c
** =============================================================================
*/

void				message(char *str, t_philo *philo);
int					std_message(char *str, int fd);

#endif