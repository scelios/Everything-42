/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:55:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/02/03 16:22:26 by beaudibe         ###   ########.fr       */
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
	int	i;
	int	size;

	i = -1;
	size = ft_lstsize(list);
	temp = list;
	while(++i < size - 1)
	{
		if (*(int *)temp->content > *(int *) (temp->next)->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

/*
{
	int	i;
	int	start_i;
	int	end_i;
	int min;
	int j;

	i = -1;
	while (++i < size)
	{
		if (list[i] == 5)
		{
			start_i = i;
			while (list[start_i] == 5)
				start_i++;
			end_i = start_i;
			j = start_i;
			while (list[end_i++] == 7)
				end_i++;
			i = end_i;
			min = ft_min(start_i - i, end_i - start_i);
			while (min-- > 0)
			{
				list[start_i++] = 0;
				list[j++] = 0;
			}
		}
	}
}




{
	int	i;
	int	j;


	j = 1;
	while (j != 0)
	{
		j = 0;
		i = -1;
		while (++i < size)
		{
			if (list[i] == a && list[i + 1] == b)
			{
				list[i] = 0;
				list[i + 1] = 0;
				i += 2;
				j++;
			}
		}
	}
}*/
