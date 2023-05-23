/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:22 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/22 12:56:22 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chrono(struct timeval start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec - start.tv_sec) * 1000 + (current.tv_usec
			- start.tv_usec) / 1000);
}

void	return_timer(t_time *time)
{
	time->until_die = chrono(time->eat);
	time->now = chrono(time->current);
}

void	ft_usleep(int n)
{
	usleep(n * 1000);
}

t_time	init_time(void)
{
	t_time	time;

	gettimeofday(&time.current, NULL);
	gettimeofday(&time.eat, NULL);
	time.until_die = 0;
	time.now = 0;
	return (time);
}

int	ft_check_numeric(int a, char **b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a)
	{
		j = 0;
		if (b[i][0] == '-')
			return (ERROR);
		if (ft_strlen(b[i] + j) >= 10 \
		&& ft_strncmp(b[i] + j, "2147483647", 10))
			return (ERROR);
		while (b[i][j])
		{
			if (!ft_isdigit(b[i][j]))
				return (ERROR);
			j++;
		}
	}
	return (SUCCESS);
}
