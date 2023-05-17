/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:38:05 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/16 21:38:05 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_die_write(t_philo *philo)
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
		printf("%d %d died\n", philo->current_timer, philo->philo);
		philo->status = DIED;
		*philo->died = 1;
		return (1);
	}
	return (0);
}

void	ft_write(t_philo *philo, int a)
{
	pthread_mutex_lock(&philo->print_mutex[0]);
	if (ft_check_die_write(philo) == 1)
	{
		pthread_mutex_unlock(&philo->print_mutex[0]);
		return ;
	}
	ft_chrono(philo->current_time);
	if (a == SLEEP)
		printf("%d %d is sleeping \n", philo->current_timer, philo->philo);
	else if (a == THINK)
		printf("%d %d is thinking \n", philo->current_timer, philo->philo);
	else if (a == EAT)
	{
		printf("%d %d has taken a fork \n", philo->current_timer, philo->philo);
		printf("%d %d has taken a fork \n", philo->current_timer, philo->philo);
		printf("%d %d is eating \n", philo->current_timer, philo->philo);
	}
	else if (a == DIED)
	{
		*philo->died = 1;
		printf("%d %d died\n", philo->current_timer, philo->philo);
	}
	pthread_mutex_unlock(&philo->print_mutex[0]);
}
