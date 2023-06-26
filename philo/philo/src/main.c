/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:53:29 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:53:29 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->nb_philo)
	{
		pthread_mutex_destroy(&main->forks_mutex[i]);
		pthread_mutex_destroy(&main->param_mutex[i]);
		pthread_mutex_destroy(&main->time_mutex[i]);
	}
	free(main->param_mutex);
	free(main->time_mutex);
	free(main->forks_mutex);
	pthread_mutex_destroy(&main->dead_mutex);
	pthread_mutex_destroy(&main->print_mutex);
}

static void	destruct(t_main *main, t_thread *thread)
{
	free(main->philo);
	if (thread != NULL)
		free(thread);
	destroy(main);
}

int	main(int a, char **b)
{
	t_main		main;
	t_thread	*thread;

	if (a != 5 && a != 6)
		return (ERROR);
	if (init_main(a, b, &main) == ERROR)
		return (ERROR);
	thread = create_and_detach_threads(&main, philo_routine);
	if (thread == NULL)
	{
		destruct(&main, 0);
		return (ERROR);
	}
	death_watcher(&main);
	destruct(&main, thread);
	return (SUCCESS);
}
