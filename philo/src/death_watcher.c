/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:37:54 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/18 22:37:54 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_have_eaten(t_main *main)
{
	int i;
	int	status;
	i = -1;
	while (++i < main->nb_philo)
	{
		pthread_mutex_lock(&main->philo[i].param_mutex);
		status = main->philo[i].status;
		pthread_mutex_unlock(&main->philo[i].param_mutex);
		if (status != END)
			return (FALSE);
	}
	return (TRUE);
}

static int	is_dead(t_philo *philo)
{
	t_time	time;
	int		time_to_die;
	int		status;
	pthread_mutex_lock(&philo->param_mutex);
	return_timer(&philo->time);
	time = philo->time;
	status = philo->status;
	time_to_die = philo->params.time_to_die;
	pthread_mutex_unlock(&philo->param_mutex);
	if (time.until_die > time_to_die && status != END)
		return (TRUE);
	return (FALSE);
}

void death_watcher(t_main *main)
{
	int i;

	i = -1;
	while (all_have_eaten(main) == FALSE)
	{
		while (++i < main->nb_philo)
		{
			if (is_dead(&main->philo[i]) == TRUE)
			{
				pthread_mutex_lock(&main->print_mutex);
				pthread_mutex_lock(&main->philo[i].param_mutex);
				if (main->philo[i].status != END)
					printf("%d %d died\n", main->philo[i].time.now, \
						main->philo[i].id);
				pthread_mutex_unlock(&main->philo[i].param_mutex);
				pthread_mutex_unlock(&main->print_mutex);
				return ;
			}
		}
		usleep(100);
		i = -1;
	}
	printf("All have eaten\n");
}
