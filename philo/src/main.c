/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:52:28 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/18 19:52:28 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



static t_philo *init_philo(int nb_philo, int a, char **b, t_main *main)
{
	t_philo *philo;
	int 	i;
	t_time	time;

	time = init_time();
	i = -1;
	philo = malloc(sizeof(t_philo) * nb_philo);
	if (philo == NULL)
		return (NULL);
	while (++i < nb_philo)
	{
		pthread_mutex_init(&philo[i].forks, NULL);
		pthread_mutex_init(&philo[i].param_mutex, NULL);
		pthread_mutex_init(&philo[i].time_mutex, NULL);
		philo[i].print_mutex = &main->print_mutex;
		philo[i].id = i;
		philo[i].params.nb_philo = nb_philo;
		philo[i].params.time_to_die = ft_atoi(b[2]);
		philo[i].params.time_to_eat = ft_atoi(b[3]);
		philo[i].params.time_to_sleep = ft_atoi(b[4]);
		if (a == 6)
			philo[i].params.nb_must_eat = ft_atoi(b[5]);
		else
			philo[i].params.nb_must_eat = -1;
		philo[i].status = 0;
		philo[i].time = time;
	}
	return (philo);
}

static int init_main(int a, char **b, t_main *main)
{
	if (ft_check_numeric(a, b) == ERROR)
		return (ERROR);
	main->nb_philo = ft_atoi(b[1]);
	pthread_mutex_init(&main->print_mutex, NULL);
	main->philo = init_philo(main->nb_philo, a, b, main);
	if (main->philo == NULL)
	{
		pthread_mutex_destroy(&main->print_mutex);
		return (ERROR);
	}
	return (SUCCESS);

}

static void destruct(t_main *main)
{
	int i;

	i = -1;
	while (++i < main->nb_philo)
	{
		// pthread_mutex_destroy(&main->philo[i].forks);
		// pthread_mutex_destroy(&main->philo[i].param_mutex);
		// pthread_mutex_destroy(&main->philo[i].time_mutex);
	}
	pthread_mutex_lock(&main->print_mutex);
	free(main->philo);
	pthread_mutex_unlock(&main->print_mutex);
	pthread_mutex_destroy(&main->print_mutex);

}

int main(int a, char **b)
{
	t_main	main;
	t_thread	*thread;
	if (a != 5 && a != 6)
		return (ERROR);
	 if (init_main(a, b, &main) == ERROR)
		return (ERROR);
	if (main.nb_philo % 2 == 0)
	{
		thread = create_and_detach_threads_even(&main);
		if (thread == NULL)
		{
			destruct(&main);
			return (ERROR);
		}
	}
	else if (main.nb_philo % 2 != 0)
	{
		thread = create_and_detach_threads_odd(&main);
		if (thread == NULL)
		{
			destruct(&main);
			return (ERROR);
		}
	}
	death_watcher(&main);
	pthread_mutex_lock(&main.print_mutex);
	free(thread);
	pthread_mutex_unlock(&main.print_mutex);
	destruct(&main);

	return (SUCCESS);
}
