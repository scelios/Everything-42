/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:30:31 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/23 14:30:31 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_trylock(t_philo *philo)
{
	while (philo->lock[philo->philo] == LOCK \
	|| philo->lock[(philo->philo + 1) % philo->nb_philo] == LOCK)
	{
		if (philo->status != THINK)
		{
			printf("%d %d is thinking %d\n", philo->current_timer, philo->philo, philo->chrono);
			philo->status = THINK;
		}
		if (ft_check_die(philo))
		{
			philo->status = DIED;
			printf("%d %d died  HAHAHAHAHAHAHAHA %d\n", philo->current_timer, philo->philo, philo->chrono);
			return (1);
		}
		usleep(100);
	}
	return (0);
}

t_philo	*ft_make_eat(t_philo *philo)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	pthread_mutex_lock(&philo->forks[philo->philo]);
	pthread_mutex_lock(&philo->forks[(philo->philo + 1) % philo->nb_philo]);
	philo->lock[philo->philo] = LOCK;
	philo->lock[(philo->philo + 1) % philo->nb_philo] = LOCK;
	philo->chrono = ft_chrono(philo->chrono_time);
	printf("%d %d has taken a fork\n", philo->current_timer, philo->philo);
	printf("%d %d has taken a fork\n", philo->current_timer, philo->philo);
	printf("%d %d is eating %d\n", philo->current_timer, philo->philo, philo->chrono);
	ft_wait(philo, philo->time_to_eat);
	pthread_mutex_unlock(&philo->forks[philo->philo]);
	pthread_mutex_unlock(&philo->forks[(philo->philo + 1) % philo->nb_philo]);
	philo->lock[philo->philo] = UNLOCK;
	philo->lock[(philo->philo + 1) % philo->nb_philo] = UNLOCK;
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->status = EAT;
	if (philo->chrono > philo->time_to_die)
		philo->status = DIED;
	return (philo);
}

void	ft_eat(t_philo *philo)
{
	if (philo->status == DIED)
		return ;
	philo->chrono = ft_chrono(philo->chrono_time);
	if (philo->nb_philo < 2 || philo->chrono
		+ philo->time_to_eat > philo->time_to_die)
	{
		if (philo->status != THINK)
			printf("%d %d is thinking %d\n", philo->current_timer, philo->philo, philo->chrono);
		ft_wait(philo, (ft_return_timer(philo, \
		philo->time_to_die - philo->chrono)));
		philo->status = DIED;
		return ;
	}
	if (ft_trylock(philo))
	{
		philo->status = DIED;
		return ;
	}
	philo = ft_make_eat(philo);
	if (philo->status == DIED)
		return ;
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->nb_must_eat--;
}
