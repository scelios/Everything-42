/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:57:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/02 11:48:32 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
#include <sys/time.h>
# include "../libft/includes/libft.h"
# include <pthread.h>

typedef struct s_philo
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
	pthread_mutex_t *forks;
	int	philo;
	int	status;
	int	chrono;
	int	current_timer;
	struct timeval	current_time;
	struct timeval	chrono_time;
}	t_philo;

#endif
