/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:31:58 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/23 14:31:58 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(t_philo *philo, int a)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	a = ft_return_timer(philo, a);
	while (ft_chrono(current) < a)
	{
		usleep(100);
	}
}

int	ft_free(t_philo philo)
{
	if (!philo.forks)
		free(philo.lock);
	if (!philo.lock)
		free(philo.forks);
	return (-1);
}

t_philo	ft_init_philo(int a, char **b)
{
	t_philo	philo;

	if (ft_check_numeric(a, b))
	{
		ft_putstr_fd("Error: non numeric variable\n", 2);
		philo.nb_philo = -1;
		return (philo);
	}
	philo.nb_philo = ft_atoi(b[1]);
	philo.forks = malloc((philo.nb_philo + 1) * sizeof(pthread_mutex_t));
	philo.time_to_die = ft_atoi(b[2]);
	philo.time_to_eat = ft_atoi(b[3]);
	philo.time_to_sleep = ft_atoi(b[4]);
	philo.nb_must_eat = -1;
	philo.lock = ft_calloc(philo.nb_philo + 1, sizeof(int));
	if (a == 6)
		philo.nb_must_eat = ft_atoi(b[5]);
	if (!philo.forks || !philo.lock)
		philo.nb_philo = ft_free(philo);
	return (philo);
}

int	ft_chrono(struct timeval start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec - start.tv_sec) * 1000 \
	+ (current.tv_usec - start.tv_usec) / 1000);
}

int	ft_return_timer(t_philo *philo, int time)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	if (philo->chrono + time <= philo->time_to_die)
		return (time);
	return (0);
}
