/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:58:41 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/16 14:54:36 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_numeric(int a, char **b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a)
	{
		j = 0;
		if (b[i][0] == '-')
			j++;
		if (ft_strlen(b[i] + j) >= 10 && ft_strncmp(b[i] + j, "2147483647", 10))
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

static t_philo	ft_init_philo(int a, char **b)
{
	t_philo	philo;

	if (ft_check_numeric(a, b))
	{
		ft_putstr_fd("Error: non numeric variable\n", 2);
		philo.nb_philo = -1;
		return (philo);
	}
	philo.nb_philo = ft_atoi(b[1]);
	philo.forks = malloc((philo.nb_philo + 1) * sizeof(pthread_mutex_t));
	philo.time_to_die = ft_atoi(b[2]);
	philo.time_to_eat = ft_atoi(b[3]);
	philo.time_to_sleep = ft_atoi(b[4]);
	philo.nb_must_eat = -1;
	if (a == 6)
		philo.nb_must_eat = ft_atoi(b[5]);
	return (philo);
}

int	ft_chrono(struct timeval start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec - start.tv_sec) * 1000 + (current.tv_usec - start.tv_usec) / 1000);
}

/*void *ft_philo_peer(void *arg)
{
	t_philo	*philo;
	struct timeval	chrono;
	struct timeval	current_time;
	int		time_ms[2];
	int		state;

	state = 0;
	gettimeofday(&chrono, NULL);
	gettimeofday(&current_time, NULL);
	philo = (t_philo *)arg;
	while (philo->nb_must_eat != 0)
	{
		time_ms[0] = ft_chrono(current_time);
		time_ms[1] = ft_chrono(chrono);
		if (time_ms[1] >= philo->time_to_die)
		{
			printf("%d %d died %d OOOOOOOOOOOOOOO\n",time_ms[0], philo->philo, time_ms[1]);
			break;
		}
		//printf("%d philo->nb_before_eat = %d\n",philo->philo, ++philo->nb_before_eat % 2);
		if ((philo->nb_philo > 1 && ++philo->nb_before_eat % 2 )&&\
		forks[philo->philo] == 0 &&	forks[(philo->philo + 1) % philo->nb_philo] == 0 )
		{
			// printf("%d %d has taken a fork\n",time_ms[0] , philo->philo);
			// printf("%d %d has taken a fork\n",time_ms[0] , philo->philo);
			printf("%d %d is eating\n",time_ms[0], philo->philo);
			forks[philo->philo] = 1;
			forks[(philo->philo + 1) % philo->nb_philo] = 1;
			usleep(philo->time_to_eat * 1000);
			philo->nb_must_eat--;
			forks[philo->philo] = 0;
			forks[(philo->philo + 1) % philo->nb_philo] = 0;
			time_ms[0] = ft_chrono(current_time);
			//printf("%d %d drops a fork\n",time_ms[0] , philo->philo);
			state = 1;
			gettimeofday(&chrono, NULL);
			time_ms[1] = ft_chrono(chrono);
			// printf("%d %d is sleeping\n",time_ms[0] , philo->philo);
			// if (time_ms[1] + philo->time_to_sleep < philo->time_to_die)
				// usleep(philo->time_to_sleep * 1000);
			// else if (philo->time_to_die - time_ms[1] > 0)
				// usleep((philo->time_to_die - time_ms[1]) * 1000);
			state = 0;
			printf("%d %d is sleeping\n",time_ms[0] , philo->philo);
			if (time_ms[1] + philo->time_to_sleep < philo->time_to_die)
				usleep(philo->time_to_sleep * 1000);
			else if (philo->time_to_die - time_ms[1] > 0)
				usleep((philo->time_to_die - time_ms[1]) * 1000);
		}
		//else if (philo->time_to_die - time_ms[1] - 50 > 0 && state != 1)
		//else if (state == 0 && time_ms[1] + philo->time_to_eat < philo->time_to_die)
		else if (state != 2 && time_ms[1] + philo->time_to_eat < philo->time_to_die)
		{
			printf("%d %d is thinking\n",time_ms[0] , philo->philo);
			//if (time_ms[1] + philo->time_to_eat < philo->time_to_die)
			usleep((philo->time_to_eat ) * 1000);
			state = 2;
		}
	}
	return (NULL);
}*/

int	ft_return_timer(t_philo	*philo, int time)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	if (philo->chrono + time < philo->time_to_die)
		return (time);
	return (0);
}

int	ft_check_die(t_philo *philo)
{
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	if (philo->chrono >= philo->time_to_die || philo->status == 3)
	{
		if (philo->status == 3)
			usleep(ft_return_timer(philo, philo->time_to_die) * 1000);
		printf("%d %d died %d OOOOOOOOOOOOOOO\n", philo->current_timer, philo->philo, philo->chrono);
		philo->status = 3;
		return (1);
	}
	return (0);
}

void	ft_think(t_philo *philo)
{
	if (philo->status == 2 || philo->status == 3)
	{
		usleep(ft_return_timer(philo, philo->time_to_die) * 1000);
		return ;
	}
	philo->status = 2;
	printf("%d %d is thinking%d\n",philo->current_timer , philo->philo,philo->chrono);
	usleep(ft_return_timer(philo, philo->time_to_eat) * 1000);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	if (philo->chrono > philo->time_to_die)
		philo->status = 3;
}

void	ft_eat(t_philo	*philo)
{
	if (philo->status == 3)
	{
		usleep(ft_return_timer(philo, philo->time_to_die) * 1000);
		return ;
	}
	//if (philo->nb_philo < 2 || philo->chrono + philo->time_to_eat > philo->time_to_die
	//|| philo->chrono > philo->time_to_die)
	philo->chrono = ft_chrono(philo->chrono_time);
	if (philo->nb_philo < 2 || philo->chrono + philo->time_to_eat > philo->time_to_die)
	{
		if (philo->status != 2)
			printf("%d %d is thinking INSTEAD OF EATING %d\n",philo->current_timer , philo->philo, philo->chrono);
		if (philo->time_to_die - philo->chrono > 0)
			usleep(ft_return_timer(philo, philo->time_to_die - philo->chrono) * 1000);
		philo->status = 3;
		return ;
	}
	philo->chrono = ft_chrono(philo->chrono_time);
	printf("%d %d before %d\n",philo->current_timer, philo->philo,philo->chrono);
	pthread_mutex_lock(&philo->forks[philo->philo]);
	pthread_mutex_lock(&philo->forks[(philo->philo + 1) % philo->nb_philo]);
	philo->chrono = ft_chrono(philo->chrono_time);
	// printf("%d %d has taken a fork\n",philo->current_timer, philo->philo);
	// printf("%d %d has taken a fork\n",philo->current_timer, philo->philo);
	printf("%d %d is eating %d\n",philo->current_timer, philo->philo,philo->chrono);
	usleep(ft_return_timer(philo, philo->time_to_eat) * 1000);
	pthread_mutex_unlock(&philo->forks[philo->philo]);
	pthread_mutex_unlock(&philo->forks[(philo->philo + 1) % philo->nb_philo]);
	philo->chrono = ft_chrono(philo->chrono_time);
	printf("%d %d drop forks %d\n",philo->current_timer, philo->philo,philo->chrono);
	philo->status = 1;
	if (philo->chrono > philo->time_to_die)
	{
		philo->status = 3;
		return ;
	}
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->nb_must_eat--;
}

void	ft_sleep(t_philo *philo)
{
	if (philo->status != 1 || philo->status == 3)
	{
		usleep(ft_return_timer(philo, philo->time_to_die) * 1000);
		return ;
	}
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->current_timer = ft_chrono(philo->current_time);
	printf("%d %d is sleeping%d  %d\n",philo->current_timer , philo->philo,philo->chrono,ft_return_timer(philo, philo->time_to_sleep));
	usleep(ft_return_timer(philo, philo->time_to_sleep) * 1000);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	philo->status = 0;
	if (philo->chrono > philo->time_to_die)
	{
		philo->status = 3;
		return ;
	}
	//printf("%d %d CHECKPOINT SLEEP %d\n",philo->current_timer, philo->philo,philo->chrono);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
}

void ft_philo_odd(t_philo *philo)
{
	int		first;

	first = 0;
	philo->status = -1;
	gettimeofday(&philo->current_time, NULL);
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	while(philo->nb_must_eat != 0)
	{
		//philo->current_timer = ft_chrono(philo->current_time);
		//philo->chrono = ft_chrono(philo->chrono_time);
		if (philo->philo % 3 == 0)
		{
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_eat(philo);
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_sleep(philo);
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_think(philo);
		}
		else if (philo->philo % 3 == 1)
		{
			if (ft_check_die(philo))
				return ;
			ft_think(philo);
			if (ft_check_die(philo))
				return ;
			ft_eat(philo);
			if (ft_check_die(philo))
				return ;
			ft_sleep(philo);
		}
		else if (philo->philo % 3 == 2)
		{
			if (ft_check_die(philo))
				return ;
			ft_think(philo);
			if (first++ == 0 && !ft_check_die(philo))
				usleep(ft_return_timer(philo, philo->time_to_eat) * 1000);
			if (ft_check_die(philo))
				return ;
			ft_eat(philo);
			if (ft_check_die(philo))
				return ;
			ft_sleep(philo);
		}
	}
}

void ft_philo_peer(t_philo *philo)
{
	philo->status = -1;
	gettimeofday(&philo->current_time, NULL);
	gettimeofday(&philo->chrono_time, NULL);
	philo->current_timer = ft_chrono(philo->current_time);
	philo->chrono = ft_chrono(philo->chrono_time);
	while(philo->nb_must_eat != 0)
	{
		// philo->current_timer = ft_chrono(philo->current_time);
		// philo->chrono = ft_chrono(philo->chrono_time);
		if (philo->philo % 2 == 0)
		{
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_eat(philo);
			// philo->chrono = ft_chrono(philo->chrono_time);
			// philo->current_timer = ft_chrono(philo->current_time);
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_sleep(philo);
		}
		else
		{
			if (ft_check_die(philo))
				return ;
			if (philo->status == -1)
			{
				ft_think(philo);
				// philo->current_timer = ft_chrono(philo->current_time);
				// philo->chrono = ft_chrono(philo->chrono_time);
				philo->status = 2;
			}
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_eat(philo);
			// philo->current_timer = ft_chrono(philo->current_time);
			// philo->chrono = ft_chrono(philo->chrono_time);
			if (ft_check_die(philo))
				return ;
			//printf("%d %d CHECKPOINT %d\n",philo->current_timer, philo->philo,philo->chrono);
			ft_sleep(philo);
		}
	}
}

void *ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nb_philo % 2 == 0)
		ft_philo_peer(philo);
	else
		ft_philo_odd(philo);
	return (NULL);
}

int		main(int a, char **b)
{
	t_philo	philo;
	pthread_t *threads;
	t_philo *philo_thread;
	int i;

	if (a != 5 && a != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	philo = ft_init_philo(a,b);
	if (philo.nb_philo == -1)
		return (1);
	threads = malloc(sizeof(pthread_t) * philo.nb_philo);
	philo_thread = malloc(sizeof(t_philo) * philo.nb_philo);
	if (!philo_thread || !threads)
	{
		free(philo.forks);
		if (!threads)
			free(threads);
		return (1);
	}
	i = -1;
	while(++i < philo.nb_philo)
	{
		philo_thread[i] = philo;
		philo_thread[i].philo = i;
		pthread_mutex_init(&philo.forks[i], NULL);
		if (pthread_create(&threads[i], NULL, ft_philo, &philo_thread[i]) != 0)
		{
			printf("Error: failed to create thread\n");
			return (1);
		}
	}
	i = -1;
	while(++i < philo.nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			printf("Error: failed to join thread\n");
			return (1);
		}
	}
	i = -1;
	while(++i < philo.nb_philo)
		pthread_mutex_destroy(&philo.forks[i]);
	free(philo.forks);
	free(threads);
	free(philo_thread);
	return (0);
}
