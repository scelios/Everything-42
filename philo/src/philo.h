/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:05:06 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 13:05:06 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	int				until_die;
	int				now;
	struct timeval	current;
	struct timeval	eat;
}	t_time;

typedef struct s_param
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
	int	nb_philo;
}	t_param;

typedef struct s_philo
{
	int			status;
	int			id;
	pthread_t	thread;
	t_time		time;
	t_param		params;
}	t_philo;

typedef struct s_main
{
	t_philo			*philo;
	int				nb_philo;
	int				dead;
	pthread_mutex_t	*param_mutex;
	pthread_mutex_t	*time_mutex;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	print_mutex;

}	t_main;

typedef struct s_thread
{
	t_main	*main;
	int		id;
}	t_thread;

typedef void	*(*t_threadfunction)(void *);

t_thread	*create_and_detach_threads(t_main *main, \
	t_threadfunction threadFunction);
void		*philo_routine(void *arg);
void		*philo_routine_odd(void *arg);
void		ft_eat(t_main *main, int id);

int			init_main(int a, char **b, t_main *main);

int			chrono(struct timeval start);
void		return_timer(t_time *time);
int			ft_check_numeric(int a, char **b);
void		ft_usleep(int n);
t_time		init_time(void);
int			should_stop(t_main *main);
int			bigger(int a, int b);
int			smaller(int a, int b);

void		ft_write(t_main *main, int id, int a);
int			is_useless(t_main *main, int id);
void		change_status(t_main *main, int id, int status);

void		death_watcher(t_main *main);

int			ft_isdigit(int c);
int			ft_atoi(const char *n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);

#endif
