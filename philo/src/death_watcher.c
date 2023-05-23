/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:53:09 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:53:09 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_have_eaten(t_main *main)
{
	int	id;

	id = -1;
	while (++id < main->nb_philo)
	{
		pthread_mutex_lock(&main->param_mutex[id]);
		if (main->philo[id].status != END)
		{
			pthread_mutex_unlock(&main->param_mutex[id]);
			return (ERROR);
		}
		pthread_mutex_unlock(&main->param_mutex[id]);
	}
	return (SUCCESS);
}

int	is_dead(t_main *main, int id)
{
	pthread_mutex_lock(&main->time_mutex[id]);
	return_timer(&main->philo[id].time);
	pthread_mutex_unlock(&main->time_mutex[id]);
	pthread_mutex_lock(&main->param_mutex[id]);
	if (main->philo[id].time.until_die > main->philo[id].params.time_to_die
		&& main->philo[id].status != END)
	{
		pthread_mutex_unlock(&main->param_mutex[id]);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&main->param_mutex[id]);
	return (ERROR);
}

void	death_watcher(t_main *main)
{
	int	id;

	while (all_have_eaten(main) != SUCCESS)
	{
		id = -1;
		while (++id < main->nb_philo)
		{
			if (is_dead(main, id) == SUCCESS)
			{
				pthread_mutex_lock(&main->print_mutex);
				printf("%d %d died\n", main->philo[id].time.now, \
						main->philo[id].id);
				pthread_mutex_unlock(&main->print_mutex);
				pthread_mutex_lock(&main->dead_mutex);
				main->dead = TRUE;
				pthread_mutex_unlock(&main->dead_mutex);
				return ;
			}
		}
		usleep(100);
	}
	printf("All have eaten\n");
}