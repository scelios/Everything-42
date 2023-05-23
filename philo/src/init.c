/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:42:54 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 14:37:11 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo2(int nb_philo, int a, char **b, t_main *main)
{
	int		i;
	t_time	time;

	time = init_time();
	i = -1;
	while (++i < nb_philo)
	{
		pthread_mutex_init(&main->forks_mutex[i], NULL);
		pthread_mutex_init(&main->param_mutex[i], NULL);
		pthread_mutex_init(&main->time_mutex[i], NULL);
		main->philo[i].id = i;
		main->philo[i].params.nb_philo = nb_philo;
		main->philo[i].params.time_to_die = ft_atoi(b[2]);
		main->philo[i].params.time_to_eat = ft_atoi(b[3]);
		main->philo[i].params.time_to_sleep = ft_atoi(b[4]);
		if (a == 6)
			main->philo[i].params.nb_must_eat = ft_atoi(b[5]);
		else
			main->philo[i].params.nb_must_eat = -1;
		main->philo[i].status = 0;
		main->philo[i].time = time;
	}
}

static t_philo	*init_philo(int nb_philo, int a, char **b, t_main *main)
{
	main->philo = malloc(sizeof(t_philo) * nb_philo);
	main->param_mutex = malloc(sizeof(pthread_mutex_t) * nb_philo);
	main->time_mutex = malloc(sizeof(pthread_mutex_t) * nb_philo);
	main->forks_mutex = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (main->philo == NULL || main->param_mutex == NULL \
	|| main->time_mutex == NULL || main->forks_mutex == NULL)
	{
		if (main->philo != NULL)
			free(main->philo);
		if (main->param_mutex != NULL)
			free(main->param_mutex);
		if (main->time_mutex != NULL)
			free(main->time_mutex);
		if (main->forks_mutex != NULL)
			free(main->forks_mutex);
		return (NULL);
	}
	init_philo2(nb_philo, a, b, main);
	return (main->philo);
}

int	init_main(int a, char **b, t_main *main)
{
	if (ft_check_numeric(a, b) == ERROR)
		return (ERROR);
	main->dead = FALSE;
	main->nb_philo = ft_atoi(b[1]);
	pthread_mutex_init(&main->print_mutex, NULL);
	pthread_mutex_init(&main->dead_mutex, NULL);
	main->philo = init_philo(main->nb_philo, a, b, main);
	if (main->philo == NULL)
	{
		pthread_mutex_destroy(&main->print_mutex);
		return (ERROR);
	}
	return (SUCCESS);
}
