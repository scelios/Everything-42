/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:18:42 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/18 21:18:42 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_thread	*create_and_detach_threads_even(t_main *main)
{
	int i;
	i = -1;

	while (++i < main->nb_philo)
	{
		if (pthread_create(&main->philo[i].thread, NULL, &philo_routine_even, \
			&main->philo[i]) != 0)
			return (0);
		pthread_detach(main->philo[i].thread);
	}
	return (0);
}

/*int create_and_detach_threads_odd(t_main *main)
{
	int i;
	t_thread *new;
	i = -1;
	while (++i < main->nb_philo)
	{
		new = malloc(sizeof(t_thread));
		if (new == NULL)
			return (ERROR);
		new->main = main;
		new->id = new->main->philo[i].id;
		if (pthread_create(&new->main->philo[i].thread, NULL, &philo_routine_odd, new) != 0)
		{
			free(new);
			return (ERROR);
		}
		pthread_detach(new->main->philo[i].thread);
		free(new);
	}
	return (SUCCESS);
}*/

t_thread *create_and_detach_threads_odd(t_main *main)
{
	int i;
	t_thread *new = malloc(sizeof(t_thread) * main->nb_philo);
	if (!new)
		return (NULL);
	i = -1;

	while (++i < main->nb_philo)
	{
		new[i].id = main->philo[i].id;
		new[i].main = main;
		printf("new->id = %d\n", new[i].id);
		if (pthread_create(&new->main->philo[i].thread, NULL, &philo_routine_odd, &new[i]) != 0)
		{
			free(new);
			return (NULL);
		}
		//pthread_detach(new->main->philo[i].thread);
	}
	i = -1;
	while (++i < main->nb_philo)
		pthread_detach(new->main->philo[i].thread);
	return (new);
}

