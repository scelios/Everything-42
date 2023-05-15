/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:57:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 17:15:09 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include <sys/time.h>
# include "../libft/includes/libft.h"
# include <pthread.h>

# define LOCK 1
# define UNLOCK 0

# define SLEEP 0
# define EAT 1
# define THINK 2
# define DIED 3

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				philo;
	int				status;
	int				chrono;
	int				current_timer;
	struct timeval	current_time;
	struct timeval	chrono_time;
	int				*died;
	int				*lock;
	pthread_mutex_t	*forks;
}	t_philo;

void	*ft_philo(void *arg);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_wait(t_philo *philo, int a);
void	ft_eat(t_philo *philo);

int		ft_return_timer(t_philo *philo, int time);
int		ft_chrono(struct timeval start);
int		ft_check_die(t_philo *philo);
int		ft_check_numeric(int a, char **b);
int		ft_return_timer(t_philo *philo, int time);
int		ft_chrono(struct timeval start);
int		ft_philo_odd(t_philo *philo);
int		ft_philo_peer(t_philo *philo);

t_philo	ft_init_philo(int a, char **b);

#endif
