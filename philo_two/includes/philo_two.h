/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/19 01:34:30 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define KO			0
# define OK			1

# define DIED		0
# define ALIVE		1
# define ONE_FULL	2
# define ALL_FULL	3

int					g_state;
int					g_count_full_philos;
sem_t				*g_forks;
sem_t				*g_pickup_forks;
sem_t				*g_message_sem;
sem_t				*g_state_sem;

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
	uint64_t		eating;
	uint64_t		sleeping;
	uint64_t		thinking;
	uint64_t		taken_first_fork;
	uint64_t		taken_second_fork;
}					t_time_stamp;

typedef struct		s_philo
{
	int				philo_name;
	int				num_of_eat;
	int				state;
	t_data			data;
	t_time_stamp	*time_stamp;
	pthread_t		tid;
}					t_philo;

typedef struct		s_philo_two
{
	int				num_of_philos;
	t_philo			*philos;
}					t_philo_two;

int					check_argument(int argc, char **argv);

uint64_t			ft_get_time(void);

void				*dining(void *arg);
void				thinking(t_philo *philo);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);

void				pick_up_forks(t_philo *philo);
void				put_down_forks(t_philo *philo);
void				*check_all_full(void *arg);
void				*check_one_die(void *arg);


long				ft_atol(const char *str);
int					ft_atoi(const char *str);

int					ft_isspace(char c);
int					ft_isnum(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(const char *str);

void				close_sem(void);
void				free_all(t_philo_two *philo_two);
int					ft_finish(t_philo_two *philo_two, const char **err_msg);

#endif