/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:17 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:15:55 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

# define KO			0
# define OK			1

# define DIED		0
# define ALIVE		1
# define ONE_FULL	2
# define ALL_FULL	3

int					g_state;
sem_t				*g_forks;
sem_t				*g_pickup_forks;
sem_t				*g_write_sem;
sem_t				*g_all_full;
sem_t				*g_state_sem;
sem_t				*g_someone_die;
sem_t				*g_kill;

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
	pid_t			pid;
}					t_philo;

typedef struct		s_philo_three
{
	int				num_of_philos;
	t_philo			*philos;
}					t_philo_three;

int					check_argument(int argc, char **argv);

int					set_data(t_data *data, int argc, char **argv);
int					init_time_stamp(t_time_stamp **time_stamp);
int					set_one_philo(t_philo *philo, int name, \
									int argc, char **argv);
int					init_philos(t_philo_three *philo_three, \
									int argc, char **argv);
int					init_philo_three(t_philo_three *philo_three, \
									int argc, char **argv);

void				kill_child_process(t_philo_three *philo_three);
int					make_check_full_threads(t_philo_three *philo_three);
int					create_process(t_philo_three *philo_three);

void				write_str(char *str, t_philo *philo);

void				dining(void *arg);
void				sleeping(t_philo *philo);
void				eating(t_philo *philo);
void				thinking(t_philo *philo);

void				pick_up_forks(t_philo *philo);
void				put_down_forks(void);

void				*change_state_to_one_die(void *arg);
void				*check_all_full(void *arg);
void				*kill_child(void *arg);
void				*check_one_die(void *arg);

void				unlink_sems(void);
void				close_sem(void);
void				free_all(t_philo_three *philo_three);
int					ft_finish(t_philo_three *philo_three, const char *err_msg);

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);

int					ft_isspace(char c);
int					ft_isnum(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(const char *str);

uint64_t			ft_get_time(void);

#endif