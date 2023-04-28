/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:11:26 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/23 14:11:26 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_if_odd_2(t_philo *philo)
{
	static int	first;

	if (philo->philo % 3 == 2)
	{
		if (ft_check_die(philo))
			return (1);
		ft_think(philo);
		if (first++ == 0 && !ft_check_die(philo))
		{
			printf("%d %d is thinking%d\n", philo->current_timer, philo->philo, philo->chrono);
			ft_wait(philo, ft_return_timer(philo, philo->time_to_eat));
		}
		if (ft_check_die(philo))
			return (1);
		ft_eat(philo);
		if (ft_check_die(philo))
			return (1);
		ft_sleep(philo);
	}
	return (0);
}

static int	ft_if_odd_1(t_philo *philo)
{
	if (philo->philo % 3 == 0)
	{
		if (ft_check_die(philo))
			return (1);
		ft_eat(philo);
		if (ft_check_die(philo))
			return (1);
		ft_sleep(philo);
		if (ft_check_die(philo))
			return (1);
		ft_think(philo);
	}
	else if (philo->philo % 3 == 1)
	{
		if (ft_check_die(philo))
			return (1);
		ft_think(philo);
		if (ft_check_die(philo))
			return (1);
		ft_eat(philo);
		if (ft_check_die(philo))
			return (1);
		ft_sleep(philo);
	}
	return (0);
}

int	ft_philo_odd(t_philo *philo)
{
	philo->status = -1;
	gettimeofday(&philo->current_time, NULL);
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	while (philo->nb_must_eat != 0)
	{
		if (ft_if_odd_1(philo))
			return (1);
		if (ft_if_odd_2(philo))
			return (1);
	}
	return (0);
}

static int	ft_if_peer(t_philo *philo)
{
	if (ft_check_die(philo))
		return (1);
	if (philo->status == -1)
	{
		ft_think(philo);
		philo->status = 2;
	}
	if (ft_check_die(philo))
		return (1);
	ft_eat(philo);
	if (ft_check_die(philo))
		return (1);
	ft_sleep(philo);
	return (0);
}

int	ft_philo_peer(t_philo *philo)
{
	philo->status = -1;
	gettimeofday(&philo->current_time, NULL);
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	while (philo->nb_must_eat != 0)
	{
		if (philo->philo % 2 == 0)
		{
			if (ft_check_die(philo))
				return (1);
			ft_eat(philo);
			if (ft_check_die(philo))
				return (1);
			ft_sleep(philo);
		}
		if (ft_if_peer(philo))
			return (1);
	}
	return (0);
}
