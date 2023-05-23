/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:37 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 14:25:30 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock(t_main *main, int id)
{
	pthread_mutex_unlock(&main->forks_mutex[id]);
	pthread_mutex_unlock(&main->forks_mutex[(id + 1) % main->nb_philo]);
	if (should_stop(main) == TRUE)
		return ;
	pthread_mutex_lock(&main->time_mutex[id]);
	gettimeofday(&main->philo[id].time.eat, NULL);
	pthread_mutex_unlock(&main->time_mutex[id]);
}

void	ft_eat(t_main *main, int id)
{
	int	time;

	pthread_mutex_lock(&main->time_mutex[id]);
	time = main->philo[id].params.time_to_die - \
		main->philo[id].params.time_to_eat + main->philo[id].time.until_die;
	pthread_mutex_unlock(&main->time_mutex[id]);
	if (should_stop(main) == TRUE || time < 0)
		return ;
	pthread_mutex_lock(&main->forks_mutex[id]);
	pthread_mutex_lock(&main->time_mutex[id]);
	time = main->philo[id].params.time_to_die - \
		main->philo[id].params.time_to_eat + main->philo[id].time.until_die;
	pthread_mutex_unlock(&main->time_mutex[id]);
	if (should_stop(main) == TRUE || time < 0)
	{
		pthread_mutex_unlock(&main->forks_mutex[id]);
		return ;
	}
	pthread_mutex_lock(&main->forks_mutex[(id + 1) % main->nb_philo]);
	ft_write(main, id, EATING);
	if (should_stop(main) == TRUE)
		return ;
	ft_usleep(main->philo[id].params.time_to_eat);
	unlock(main, id);
}
