/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:03:28 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 17:59:40 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_first_big_sort(t_dlist *dlist)
{
	int	median;
	int	*nbr_of_group;
	int	size;
	int	i;

	nbr_of_group = malloc(sizeof(int) * 10000);
	dlist->size = 0;
	while (ft_lstsize(dlist->a) > 2)
	{
		size = ft_lstsize(dlist->a);
		median = ft_median(dlist->a, size);
		i = 0;
		while (!ft_all_above_median(dlist->a, median, size))
		{
			if (*(int *)dlist->a->content < median && ++i)
				ft_pb(dlist);
			else
				ft_ra(dlist);
		}
		nbr_of_group[dlist->size++] = i;
	}
	ft_resolve_little(dlist);
	return (nbr_of_group);
}

void	ft_cut_by_2_a(t_dlist *dlist, int len)
{
	int	median;
	int	nbr[10000];
	int	i;
	int	j;
	int	rotate_a;

	j = 1;
	while (ft_lstsize(dlist->a) > 2 + ft_len_is_sort(dlist->a, 1))
	{
		median = ft_median(dlist->a, len);
		i = 0;
		rotate_a = 0;
		while (!ft_all_above_median(dlist->a, median, len))
		{
			if (*(int *)dlist->a->content < median && ++i)
				ft_pb(dlist);
			else if (*(int *)dlist->a->content >= median && ++rotate_a)
				ft_ra(dlist);
		}
		nbr[j++] = i;
		while (rotate_a-- > 0)
			ft_rra(dlist);
	}
	nbr[0] = j;
	ft_resolve_little(dlist);
}

t_truc	ft_reset(t_dlist *dlist, int len)
{
	t_truc	truc;

	truc.median = 0;
	truc.i = 0;
	truc.rotate_b = 0;
	truc.rotate_a = 0;
	truc.j = 0;
	truc.temp = 0;
	truc.temp2 = 0;
	truc.nbr_groups = 0;
	truc.median = ft_median(dlist->b, len);
	return (truc);
}

t_truc	*ft_secound_part(t_dlist *dlist, t_truc *t)
{
	while (t->i > 2)
	{
		t->median = ft_median(dlist->a, t->i);
		t->j = 0;
		t->rotate_a = 0;
		while (t->i-- > 0)
		{
			if (*(int *)dlist->a->content < t->median && ++t->j)
				ft_pb(dlist);
			else if (*(int *)dlist->a->content >= t->median \
			&& ++t->rotate_a)
				ft_ra(dlist);
		}
		t->groups[t->nbr_groups++] = t->j;
		t->i = t->rotate_a;
		while (t->rotate_a-- > 0)
			ft_rra(dlist);
	}
	while (--t->nbr_groups >= 0)
	{
		ft_resolve_little(dlist);
		ft_cut_by_2_b(dlist, t->groups[t->nbr_groups], t->nbr_groups >= 0);
	}
	ft_resolve_little(dlist);
	return (t);
}

int	ft_cut_by_2_b(t_dlist *dlist, int len, int test)
{
	t_truc	truc;

	while (len > 2)
	{
		truc = ft_reset(dlist, len);
		while (len-- > 0)
		{
			if (*(int *)dlist->b->content > truc.median && ++truc.i)
				ft_pa(dlist);
			else if (*(int *)dlist->b->content <= truc.median \
					&& ++truc.rotate_b)
				ft_rb(dlist);
		}
		truc.temp = truc.rotate_b;
		while (truc.temp-- > 0 && test)
			ft_rrb(dlist);
		ft_secound_part(dlist, &truc);
		len = truc.rotate_b;
	}
	while (len-- > 0)
	{
		ft_pa(dlist);
		ft_resolve_little(dlist);
	}
	return (0);
}
/*		// while (truc.i > 2)
		// {
		// 	truc.median = ft_median(dlist->a, truc.i);
		// 	truc.j = 0;
		// 	truc.rotate_a = 0;
		// 	while (truc.i-- > 0)
		// 	{
		// 		if (*(int *)dlist->a->content < truc.median && ++truc.j)
		// 			ft_pb(dlist);
		// 		else if (*(int *)dlist->a->content >= truc.median && ++truc.rotate_a)
		// 			ft_ra(dlist);
		// 	}
		// 	truc.groups[truc.nbr_groups++] = truc.j;
		// 	truc.i = truc.rotate_a;
		// 	while (truc.rotate_a-- > 0)
		// 		ft_rra(dlist);
		// }
		// while (--truc.nbr_groups >= 0)
		// {
		// 	ft_resolve_little(dlist);
		// 	ft_cut_by_2_b(dlist, truc.groups[truc.nbr_groups], truc.nbr_groups >= 0);
		// }
		// ft_resolve_little(dlist);
int	ft_cut_by_2_b(t_dlist *dlist, int len, int test)
{
	int	median;
	int	i;
	int	rotate_b;
	int	rotate_a;
	int	j;
	int	temp;
	int	temp2;
	int	nbr_groups;
	int	groups[10000];

	while (len > 2)
	{
		median = 0;
		i = 0;
		rotate_b = 0;
		rotate_a = 0;
		j = 0;
		temp = 0;
		temp2 = 0;
		nbr_groups = 0;
		median = ft_median(dlist->b, len);
		while (len-- > 0)
		{
			if (*(int *)dlist->b->content > median && ++i)
				ft_pa(dlist);
			else if (*(int *)dlist->b->content <= median && ++rotate_b)
				ft_rb(dlist);
		}
		temp = rotate_b;
		while (temp-- > 0 && test)
			ft_rrb(dlist);
		while (i > 2)
		{
			median = ft_median(dlist->a, i);
			j = 0;
			rotate_a = 0;
			while (i-- > 0)
			{
				if (*(int *)dlist->a->content < median && ++j)
					ft_pb(dlist);
				else if (*(int *)dlist->a->content >= median && ++rotate_a)
					ft_ra(dlist);
			}
			groups[nbr_groups++] = j;
			i = rotate_a;
			while (rotate_a-- > 0)
				ft_rra(dlist);
		}
		while (--nbr_groups >= 0)
		{
			ft_resolve_little(dlist);
			ft_cut_by_2_b(dlist, groups[nbr_groups], nbr_groups >= 0);
		}
		ft_resolve_little(dlist);
		len = rotate_b;
	}
	while (len-- > 0)
	{
		ft_pa(dlist);
		ft_resolve_little(dlist);
	}
	return (0);
}*/
