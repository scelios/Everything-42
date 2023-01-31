/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:41:45 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/19 18:30:49 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static int	ft_is_sort(t_list_int *list)
{
	t_list_int	*current;
	int			i;

	i = 0;
	current = list;
	while (current->next)
	{
		if (current->content > (current->next)->content)
			i++;
		current = current->next;
	}
	return (i);
}*/

/*void	ft_sort_tab(t_list *dlist)
{
	t_list	*blist;
	t_list	*current_a;
	t_list	*current_b;
	float	median;
	int		group;

	current_a = dlist;
	blist = 0;
	group = 0;
	current_b = blist;
	while (ft_isnt_sort(dlist) && !blist)
	{
		median = ft_median(dlist);
		while (current_a->next && ft_lstsize(current_a) > 2 && ft_isnt_sort(dlist))
		{
			if ((float)current_a->content < median)
			{
				current_a->groups = group;
				ft_pb(current_a, current_b);
			}
			else
				ft_ra(current_a);
			current_a = current_a->next;
		}
		group++;
		if (!ft_isnt_sort(dlist))
			break ;
		if (ft_lstsize(current_a) < 3 && current_a->content > (current_a->next)->content)
			ft_sa(current_a);
	}
}

void	ft_sort_list(t_dlist *dlist)
{

	while (!dlist->a && ft_isnt_sort(dlist->a))
	{
		ft_cut_by_2_to_b(dlist);
		ft_resolve_for_5(dlist);
		ft_cut_by_2_to_a(dlist);
	}
}*/
