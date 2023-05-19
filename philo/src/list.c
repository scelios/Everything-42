/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:45:40 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/19 01:45:40 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
int init_list(t_main *main)
{
	int	i;
	t_list	*list;

	i = -1;
	list = malloc(sizeof(t_list) * main->nb_philo);
	if (!list)
		return (ERROR);
	while (++i < main->nb_philo)
	{
		pthread_mutex_init(main->philo[i].fork->forks, NULL);
		list[i].forks = main->philo[i].fork->forks;
		list[i].next = NULL;
	}
	while (++i < main->nb_philo - 1)
		list[i].next = &list[i + 1];
	list[i].next = &list[0];
	while (++i < main->nb_philo)
		main->philo[i].fork = &list[i];
	return (SUCCESS);
}*/
