/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:46:43 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define KO			0
# define OK			1

# define DIED		0
# define ALIVE		1
# define ONE_FULL	2
# define ALL_FULL	3

int					g_state;
int					g_count_full_philos;
pthread_mutex_t		g_state_mutex;
pthread_mutex_t		g_message_mutex;

/*
** =============================================================================
**	struct
** =============================================================================
*/

typedef struct		s_data
{
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
}					t_data;

typedef struct		s_time_stamp
{
	uint64_t		start_time;
	uint64_t		taken_fork;
	uint64_t		eating;
	uint64_t		sleeping;
	uint64_t		thinking;
}					t_time_stamp;

typedef struct		s_philo
{
	int				philo_name;
	int				num_of_eat;
	int				state;
	t_data			data;
	t_time_stamp	*time_stamp;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	pthread_t		tid;
}					t_philo;

typedef struct		s_philo_one
{
	int				num_of_philos;
	t_philo			*philos;
}					t_philo_one;

int					check_argument(int argc, char **argv);

int					init_philo_one(t_philo_one *philo_one, \
									int argc, char **argv);

int					create_threads(t_philo_one *philo_one);
int					join_threads(t_philo_one philo_one);

void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				*dining(void *arg);

void				pick_up_forks(t_philo *philo);
void				put_down_forks(t_philo *philo);

void				*check_one_die(void *temp_philo);
void				*check_all_full(void *temp_philo);

void				message(char *str, t_philo *philo);

int					ft_finish(t_philo_one *philo_one, const char *message);

uint64_t			ft_get_time(void);

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);

int					ft_isspace(char c);
int					ft_isnum(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(const char *str);

#endif
