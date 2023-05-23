/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:56:34 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(t_main *main, int id, int a)
{
	int	time_now;

	if (should_stop(main) == TRUE)
		return ;
	pthread_mutex_lock(&main->time_mutex[id]);
	time_now = main->philo[id].time.now;
	pthread_mutex_unlock(&main->time_mutex[id]);
	if (should_stop(main) == TRUE)
		return ;
	pthread_mutex_lock(&main->print_mutex);
	if (a == EATING)
	{
		printf("%d %d has taken a fork \n", time_now, id);
		printf("%d %d has taken a fork \n", time_now, id);
		printf("%d %d is eating\n", time_now, id);
	}
	else if (a == THINKING)
		printf("%d %d is thinking\n", time_now, id);
	else if (a == SLEEPING)
		printf("%d %d is sleeping\n", time_now, id);
	pthread_mutex_unlock(&main->print_mutex);
}
