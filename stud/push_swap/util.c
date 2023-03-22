/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:23:08 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 16:43:07 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_while(t_dlist *dlist, int len, void (*f)(t_dlist *dlist))
{
	while (len--)
		f(dlist);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_sort_list(t_dlist *dlist)
{
	int	*nbr_of_group;

	if (ft_lstsize(dlist->a) <= 5)
		ft_little(dlist);
	else
	{
		nbr_of_group = ft_first_big_sort(dlist);
		while (--dlist->size >= 0)
			ft_cut_by_2_b(dlist, nbr_of_group[dlist->size], dlist->size > 0);
		free(nbr_of_group);
	}
	ft_check_cmd(dlist);
	ft_print_cmd(dlist->cmds, dlist->cmds_size);
}
