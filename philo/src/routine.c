/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:51:45 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/18 21:51:45 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	*philo_routine_even(void *arg)
{
	t_philo	*philo;
	int		time_to_die;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->time.consult_mutex);
	time_to_die = philo->params.time_to_die;
	pthread_mutex_unlock(&philo->time.consult_mutex);
	if (philo->id == 1)
	{
		ft_usleep(time_to_die + 1);
	}
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(&philo->time.consult_mutex);
	printf("%d %d even\n", philo->time.now, philo->id);
	pthread_mutex_unlock(&philo->time.consult_mutex);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_lock(&philo->status_mutex);
	philo->status = END;
	pthread_mutex_unlock(&philo->status_mutex);
	return (NULL);
}*/

void	eat(t_philo *philo, t_param param)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(&philo->param_mutex);
	printf("%d %d is eating\n", philo->time.now, philo->id);
	pthread_mutex_unlock(&philo->param_mutex);
	pthread_mutex_unlock(philo->print_mutex);
	ft_usleep(param.time_to_eat);
}

void	*philo_routine_even(void *arg)
{
	(void)arg;
	/*t_philo	*philo;
	t_param	param;
	int		id;
	static int i;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->param_mutex);
	param = philo->params;
	id = philo->id;
	pthread_mutex_unlock(&philo->param_mutex);
	while (nb_must_eat--)
	{
		if (id % 2 == 0)
		{
			eat(philo, param);
			sleep(philo, param);
		}
		else
		{
			if (i++ == 0)
				ft_usleep(param.time_to_eat);
			eat(philo, param);
			sleep(philo, param);
		}
	}*/
	return (NULL);
}

void *philo_routine_odd(void *arg)
{
	t_thread *thread;
	int id;
	t_philo *philo;

	thread = (t_thread *)arg;
	pthread_mutex_lock(&thread->main->philo[thread->id].param_mutex);
	philo = &thread->main->philo[thread->id];
	id = thread->id;
	pthread_mutex_unlock(&thread->main->philo[id].param_mutex);
	while (philo->params.nb_must_eat != 0)
	{
		pthread_mutex_lock(&philo->param_mutex);
		philo->params.nb_must_eat--;
		pthread_mutex_unlock(&philo->param_mutex);
	}
	pthread_mutex_lock(&philo->param_mutex);
	philo->status = END;
	pthread_mutex_unlock(&philo->param_mutex);
	return NULL;
}

