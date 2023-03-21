/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_little.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:01:44 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 16:02:30 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resolve_little(t_dlist *dlist)
{
	if (ft_lstsize(dlist->a) >= 2 && *(int *)dlist->a->content \
	> *(int *) dlist->a->next->content)
		ft_sa(dlist);
}

void	ft_solve3(t_dlist *dlist)
{
	int	tab[3];

	tab[0] = *(int *) dlist->a->content;
	tab[1] = *(int *) dlist->a->next->content;
	tab[2] = *(int *) dlist->a->next->next->content;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		ft_sa(dlist);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		ft_sa(dlist);
		ft_rra(dlist);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ft_ra(dlist);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		ft_sa(dlist);
		ft_ra(dlist);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		ft_rra(dlist);
}

void	ft_solve5(t_dlist *dlist)
{
	while (ft_lstsize(dlist->a) > 3)
		ft_pb(dlist);
	ft_solve3(dlist);
	if (ft_lstmax(dlist->b) == *(int *) dlist->b->content)
		ft_sb(dlist);
	while (ft_lstsize(dlist->b) != 0)
	{
		ft_pa(dlist);
		if (ft_lstmax(dlist->a) == \
		*(int *) dlist->a->content && \
		ft_lstmin(dlist->a) != *(int *) dlist->a->next->content)
		{
			ft_pb(dlist);
			ft_ra(dlist);
		}
		else if (ft_lstmax(dlist->a) != \
		*(int *) dlist->a->content && \
		*(int *) dlist->a->content > *(int *) dlist->a->next->content)
		{
			ft_pb(dlist);
			ft_ra(dlist);
		}
	}
	while (ft_is_sort(dlist->a))
		ft_ra(dlist);
}

void	ft_little(t_dlist *dlist)
{
	if (ft_lstsize(dlist->a) == 1)
		return ;
	else if (ft_lstsize(dlist->a) == 2)
		ft_resolve_little(dlist);
	else if (ft_lstsize(dlist->a) == 3)
		ft_solve3(dlist);
	else if (ft_lstsize(dlist->a) <= 5)
		ft_solve5(dlist);
}
