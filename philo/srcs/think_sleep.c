/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:38:39 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/23 14:38:39 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_mutex(t_philo *philo)
{
	if (philo->lock[philo->philo] == LOCK || \
		philo->lock[(philo->philo + 1) % philo->nb_philo] == LOCK)
	{
		pthread_mutex_unlock(&philo->forks[philo->philo]);
		pthread_mutex_unlock(&philo->forks[(philo->philo + 1) % \
		philo->nb_philo]);
	}
}

int	ft_check_die(t_philo *philo)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	if (*philo->died == 1)
	{
		unlock_mutex(philo);
		philo->status = DIED;
		return (1);
	}
	if (philo->chrono >= philo->time_to_die || philo->status == DIED)
	{
		if (philo->status == DIED)
			ft_wait(philo, ft_return_timer(philo, philo->time_to_die));
		unlock_mutex(philo);
		ft_write(philo, DIED);
		philo->status = DIED;
		*philo->died = 1;
		return (1);
	}
	return (0);
}

void	ft_think(t_philo *philo)
{
	if (philo->status == THINK || philo->status == DIED)
	{
		ft_wait(philo, ft_return_timer(philo, philo->time_to_die));
		return ;
	}
	philo->status = THINK;
	ft_write(philo, THINK);
	ft_wait(philo, ft_return_timer(philo, philo->time_to_eat));
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	if (philo->chrono > philo->time_to_die)
		philo->status = DIED;
}

void	ft_sleep(t_philo *philo)
{
	if (philo->status != EAT || philo->status == DIED)
		return ;
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	ft_write(philo, SLEEP);
	ft_wait(philo, philo->time_to_sleep);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->status = SLEEP;
	if (philo->chrono > philo->time_to_die)
	{
		philo->status = DIED;
		return ;
	}
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
}
