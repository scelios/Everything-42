/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:51:49 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/18 19:51:49 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERROR -2
# define SUCCESS -1

# define TRUE 1
# define FALSE 0

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define END 4

typedef struct s_time
{
	int until_die;
	int now;
	struct timeval current;
	struct timeval eat;
} t_time;

typedef struct s_param
{
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nb_must_eat;
	int nb_philo;
} t_param;

typedef struct s_list
{
	pthread_mutex_t *forks;
	struct s_list *next;
} t_list;

typedef struct s_philo
{
	int status;
	int id;
	pthread_t thread;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t param_mutex;
	pthread_mutex_t forks;
	t_time time;
	t_param params;
} t_philo;

typedef struct s_main
{
	t_philo *philo;
	int nb_philo;
	int id;
	pthread_mutex_t print_mutex;
	pthread_mutex_t *thread_mutex;

} t_main;

typedef struct s_thread
{
	t_main *main;
	int id;
} t_thread;


t_thread 	*create_and_detach_threads_even(t_main *main);
t_thread 	*create_and_detach_threads_odd(t_main *main);
void	*philo_routine_even(void *arg);
void	*philo_routine_odd(void *arg);

int		chrono(struct timeval start);
void	return_timer(t_time *time);
int		ft_check_numeric(int a, char **b);
void	ft_usleep(int n);
t_time	init_time(void);

void	ft_write(t_philo *philo, int a);
int	 init_list(t_main *main);

void	death_watcher(t_main *main);

int		ft_isdigit(int c);
int		ft_atoi(const char *n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);


#endif
