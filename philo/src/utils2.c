/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:12:40 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 14:22:23 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_main *main)
{
	pthread_mutex_lock(&main->dead_mutex);
	if (main->dead == TRUE)
	{
		pthread_mutex_unlock(&main->dead_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&main->dead_mutex);
	return (FALSE);
}

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	change_status(t_main *main, int id, int status)
{
	pthread_mutex_lock(&main->param_mutex[id]);
	main->philo[id].status = status;
	pthread_mutex_unlock(&main->param_mutex[id]);
}

int	is_useless(t_main *main, int id)
{
	int	time_to_die;

	pthread_mutex_lock(&main->param_mutex[id]);
	time_to_die = main->philo[id].params.time_to_die;
	if (main->nb_philo == 1)
	{
		pthread_mutex_unlock(&main->param_mutex[id]);
		ft_write(main, main->philo->id, THINKING);
		ft_usleep(time_to_die + 1);
		return (TRUE);
	}
	pthread_mutex_unlock(&main->param_mutex[id]);
	return (FALSE);
}
