/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:54:27 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:54:27 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_main *main, int id)
{
	int	time;

	if (should_stop(main) == TRUE)
		return ;
	pthread_mutex_lock(&main->time_mutex[id]);
	time = main->philo[id].params.time_to_sleep;
	pthread_mutex_unlock(&main->time_mutex[id]);
	ft_write(main, id, SLEEPING);
	ft_usleep(time);
}

void	ft_think(t_main *main, int id)
{
	int	time;

	if (should_stop(main) == TRUE)
		return ;
	ft_write(main, id, THINKING);
	pthread_mutex_lock(&main->time_mutex[id]);
	time = smaller(main->philo->params.time_to_sleep, \
					main->philo->params.time_to_eat);
	pthread_mutex_unlock(&main->time_mutex[id]);
	if (time < 0)
		return ;
	ft_write(main, id, THINKING);
	ft_usleep(time);
}

int	routine_even(t_main *main, int id, int first, int *eat)
{
	if (id % 2 && first == 0)
	{
		ft_usleep(main->philo->params.time_to_eat);
	}
	if (should_stop(main) == TRUE)
		return (ERROR);
	ft_eat(main, id);
	if (--*eat == 0 || should_stop(main) == TRUE)
		return (ERROR);
	ft_sleep(main, id);
	if (should_stop(main) == TRUE)
		return (ERROR);
	return (SUCCESS);
}

int	routine_odd(t_main *main, int id, int first, int *eat)
{
	if (is_useless(main, id) == TRUE)
		return (ERROR);
	if ((first == 0 && id % 3 != 0) || (first == 1 && id % 3 == 2))
	{
		if (first == 0)
			ft_usleep(main->philo->params.time_to_eat);
		else if (first == 1 && id % 3 == 2)
			ft_usleep(main->philo->params.time_to_eat);
		if (should_stop(main) == TRUE)
			return (ERROR);
	}
	else
	{
		ft_eat(main, id);
		if (should_stop(main) == TRUE || --*eat == 0)
			return (ERROR);
		ft_sleep(main, id);
		if (should_stop(main) == TRUE)
			return (ERROR);
		ft_think(main, id);
		if (should_stop(main) == TRUE)
			return (ERROR);
	}
	return (SUCCESS);
}

void	*philo_routine(void *arg)
{
	t_thread	*thread;
	int			id;
	int			i;
	int			eat;
	t_main		*main;

	thread = (t_thread *)arg;
	i = 0;
	pthread_mutex_lock(&thread->main->param_mutex[thread->id]);
	id = thread->id;
	main = thread->main;
	eat = main->philo->params.nb_must_eat;
	pthread_mutex_unlock(&thread->main->param_mutex[thread->id]);
	while (eat != 0 && should_stop(main) == FALSE)
	{
		if (main->nb_philo % 2 == 0 && routine_even(main, id, i++, &eat) == -2)
			break ;
		else if (main->nb_philo % 2 == 1 \
		&& routine_odd(main, id, i++, &eat) == ERROR)
			break ;
	}
	change_status(main, id, END);
	return (NULL);
}
