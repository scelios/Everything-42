/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:55:39 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:55:39 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread	*create_and_detach_threads(t_main *main, \
		t_threadfunction threadFunction)
{
	int			i;
	t_thread	*new;

	new = malloc(sizeof(t_thread) * main->nb_philo);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < main->nb_philo)
	{
		new[i].id = main->philo[i].id;
		new[i].main = main;
		if (pthread_create(&new->main->philo[i].thread, NULL, threadFunction, \
				&new[i]) != 0)
		{
			free(new);
			return (NULL);
		}
	}
	i = -1;
	while (++i < main->nb_philo)
		pthread_detach(new->main->philo[i].thread);
	return (new);
}
