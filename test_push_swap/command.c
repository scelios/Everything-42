/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:46:37 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 15:47:40 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_dlist *dlist)
{
	t_list	*first_a;

	first_a = dlist->a;
	if (first_a != NULL)
	{
		dlist->a = first_a->next;
		ft_lstadd_front(&(dlist->b), ft_lstnew(malloc(sizeof(int))));
		*((int *) dlist->b->content) = *((int *)first_a->content);
		free(first_a->content);
		free(first_a);
		dlist->cmds[dlist->cmds_size++] = 1;
	}
}

void	ft_pa(t_dlist *dlist)
{
	t_list	*first_b;

	first_b = dlist->b;
	if (first_b != NULL)
	{
		dlist->b = first_b->next;
		ft_lstadd_front(&(dlist->a), ft_lstnew(malloc(sizeof(int))));
		*((int *)dlist->a->content) = *((int *)first_b->content);
		free(first_b->content);
		free(first_b);
		dlist->cmds[dlist->cmds_size++] = 2;
	}
}

void	ft_sa(t_dlist *dlist)
{
	int	temp;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		temp = *((int *) dlist->a->content);
		*((int *) dlist->a->content) = *((int *) dlist->a->next->content);
		*((int *) dlist->a->next->content) = temp;
		dlist->cmds[dlist->cmds_size++] = 3;
	}
}

void	ft_sb(t_dlist *dlist)
{
	int	temp;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		temp = *((int *) dlist->b->content);
		*((int *) dlist->b->content) = *((int *) dlist->b->next->content);
		*((int *) dlist->b->next->content) = temp;
		dlist->cmds[dlist->cmds_size++] = 4;
	}
}

void	ft_ra(t_dlist *dlist)
{
	t_list	*last;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		last = ft_lstlast(dlist->a);
		last->next = dlist->a;
		dlist->a = dlist->a->next;
		last->next->next = NULL;
		dlist->cmds[dlist->cmds_size++] = 5;
	}
}
