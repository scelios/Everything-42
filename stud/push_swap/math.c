/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:55:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 16:44:11 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_how_much_sort(t_list *list)
{
	t_list	*current;
	int		in_order;
	int		size;

	in_order = 0;
	current = list;
	size = 0;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)(current->next)->content)
			in_order++;
		current = current->next;
		size++;
	}
	return ((float)in_order / (float)size);
}

int	ft_is_sort(t_list *list)
{
	t_list	*temp;
	int		i;
	int		size;

	i = -1;
	size = ft_lstsize(list);
	temp = list;
	while (++i < size - 1)
	{
		if (*(int *)temp->content > *(int *)(temp->next)->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_median(t_list *list, int size)
{
	t_list	*current;
	int		total;
	int		i;

	i = 0;
	total = 0;
	current = list;
	while (current != NULL && i++ < size)
	{
		total += *(int *) current->content;
		current = current->next;
	}
	return ((int)((float) total / (float) size));
}

int	ft_len_is_sort(t_list *list, int start_sort)
{
	t_list	*temp;
	int		i;

	temp = list;
	i = 0;
	while (temp->next && start_sort--)
	{
		i++;
		if (*(int *)temp->content > *(int *) temp->next->content)
			i = 0;
		temp = temp->next;
	}
	return (i);
}

int	ft_all_above_median(t_list *list, int median, int len)
{
	t_list	*temp;

	temp = list;
	while (temp && len--)
	{
		if (*(int *)temp->content < median)
			return (0);
		temp = temp->next;
	}
	return (1);
}
