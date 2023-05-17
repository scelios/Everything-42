/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:47:30 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 15:48:09 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_dlist *dlist)
{
	t_list	*last;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		last = ft_lstlast(dlist->b);
		last->next = dlist->b;
		dlist->b = dlist->b->next;
		last->next->next = NULL;
		dlist->cmds[dlist->cmds_size++] = 6;
	}
}

void	ft_rra(t_dlist *dlist)
{
	t_list	*last;
	t_list	*current;
	//t_list	*first;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		current = dlist->a;
		while (current->next->next != NULL)
			current = current->next;
		last = ft_lstlast(dlist->a);
		//first = dlist->a->next;
		current->next = NULL;
		last->next = dlist->a;
		dlist->a = last;
		dlist->cmds[dlist->cmds_size++] = 7;
	}
}

void	ft_rrb(t_dlist *dlist)
{
	t_list	*last;
	t_list	*current;
	//t_list	*first;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		current = dlist->b;
		while (current->next->next != NULL)
			current = current->next;
		last = ft_lstlast(dlist->b);
		//first = dlist->b->next;
		current->next = NULL;
		last->next = dlist->b;
		dlist->b = last;
		dlist->cmds[dlist->cmds_size++] = 8;
	}
}

void	ft_rr(t_dlist *dlist)
{
	ft_ra(dlist);
	ft_rb(dlist);
	dlist->cmds[dlist->cmds_size++] = 9;
}

void	ft_rrr(t_dlist *dlist)
{
	ft_rra(dlist);
	ft_rrb(dlist);
	dlist->cmds[dlist->cmds_size++] = 10;
}
