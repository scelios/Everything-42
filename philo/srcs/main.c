/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/02/07 10:58:41 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/21 18:46:46 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_numeric(int a, char **b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a)
	{
		j = 0;
		if (b[i][0] == '-')
			j++;
		if (ft_strlen(b[i] + j) >= 10 && ft_strncmp(b[i] + j, "2147483647",
				10))
			return (1);
		while (b[i][j])
		{
			if (!ft_isdigit(b[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

static int	ft_init_join_threads(t_philo philo, pthread_t *threads, \
t_philo *philo_thread )
{
	int	i;
	int	died;

	died = 0;
	i = -1;
	while (++i < philo.nb_philo)
	{
		philo_thread[i] = philo;
		philo_thread[i].philo = i + 1;
		philo_thread[i].died = &died;
		pthread_mutex_init(&philo.forks[i], NULL);
		if (pthread_create(&threads[i], NULL, ft_philo, &philo_thread[i]) != 0)
			return (1 + 0 * printf("Error: failed to create thread\n"));
	}
	i = -1;
	while (++i < philo.nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (1 + 0 * printf("Error: failed to join thread\n"));
	}
	return (0);
}

int	ft_if_free(t_philo philo, pthread_t *threads, t_philo *philo_thread)
{
	free(philo.forks);
	if (!threads)
		free(philo_thread);
	if (!philo_thread)
		free(threads);
	return (1);
}

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nb_philo % 2 == 0)
	{
		if (ft_philo_peer(philo) == 1)
			return ((void *)1);
	}
	else
	{
		if (ft_philo_odd(philo) == 1)
			return ((void *)1);
	}
	return ((void *)0);
}

int	main(int a, char **b)
{
	t_philo		philo;
	pthread_t	*threads;
	t_philo		*philo_thread;
	int			i;

	if (a != 5 && a != 6)
		return (1 + 0 * printf("Error: wrong number of arguments\n"));
	philo = ft_init_philo(a, b);
	if (philo.nb_philo == -1)
		return (1);
	threads = malloc(sizeof(pthread_t) * philo.nb_philo);
	philo_thread = malloc(sizeof(t_philo) * philo.nb_philo);
	if (!philo_thread || !threads)
		return (ft_if_free(philo, threads, philo_thread));
	i = ft_init_join_threads(philo, threads, philo_thread);
	if (i == 1)
		return (1);
	i = -1;
	while (++i < philo.nb_philo)
		pthread_mutex_destroy(&philo.forks[i]);
	free(philo.forks);
	free(threads);
	free(philo_thread);
	free(philo.lock);
	return (0);
}
