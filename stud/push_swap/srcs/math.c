/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:55:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/20 11:57:45 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	ft_how_much_sort(t_list *list)
{
	t_list	*current;
	int		in_order;
	int		size;

	in_order = 0;
	current = list;
	while (current->next)
	{
		if (*(int *)current->content > *(int *) (current->next)->content)
			in_order++;
		current = current->next;
		size++;
	}
	return ((float)in_order / (float)size);
}

int	ft_is_sort(t_list *list)
{
	t_list *temp;

	temp = list;
	while(temp)
	{
		if (*(int *)temp->content > *(int *) (temp->next)->content)
			return (1);
		temp = temp->next;
	}
}

