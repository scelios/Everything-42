/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:23:21 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/19 01:23:21 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(t_philo *philo, int a)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(&philo->param_mutex);
	if (a == EATING)
	{
		printf("%d %d has taken a fork \n", philo->time.now, philo->id);
		printf("%d %d has taken a fork \n", philo->time.now, philo->id);
		printf("%d %d is eating\n", philo->time.now, philo->id);
	}
	else if (a == THINKING)
		printf("%d %d is thinking\n", philo->time.now, philo->id);
	else if (a == SLEEPING)
		printf("%d %d is sleeping\n", philo->time.now, philo->id);
	pthread_mutex_unlock(&philo->param_mutex);
	pthread_mutex_unlock(philo->print_mutex);
}
