/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:01:07 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 16:01:33 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmax(t_list *list)
{
	int	max;

	max = *(int *) list->content;
	while (list)
	{
		if (*(int *) list->content > max)
			max = *(int *) list->content;
		list = list->next;
	}
	return (max);
}

int	ft_lstmin(t_list *list)
{
	int	min;

	min = *(int *) list->content;
	while (list)
	{
		if (*(int *) list->content < min)
			min = *(int *) list->content;
		list = list->next;
	}
	return (min);
}
