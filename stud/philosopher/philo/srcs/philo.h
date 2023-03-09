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
#include <sys/time.h>
# include "../libft/includes/libft.h"
# include <pthread.h>

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
	pthread_mutex_t *forks;
}	t_philo;

#endif
