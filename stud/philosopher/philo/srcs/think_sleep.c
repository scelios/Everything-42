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

int	ft_check_die(t_philo *philo)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	if (*philo->died == 1)
	{
		philo->status = DIED;
		return (1);
	}
	if (philo->chrono >= philo->time_to_die || philo->status == DIED)
	{
		if (philo->status == DIED)
		{
			ft_wait(philo, ft_return_timer(philo, philo->time_to_die));
		}
		printf("%d %d died %d\n", philo->current_timer, philo->philo, philo->chrono);
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
	printf("%d %d is thinking%d\n", philo->current_timer, philo->philo, philo->chrono);
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
	printf("%d %d is sleeping %d\n", philo->current_timer, philo->philo, philo->chrono);
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
