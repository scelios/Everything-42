/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:35:15 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:20 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_dlist *dlist)
{
	t_list	*tmp;

	tmp = dlist->a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int a, char **b)
{
	t_dlist	dlist;
	int		*tab;

	dlist.cmds_size = 0;
	if (a == 2)
		return (0);
	dlist.cmds = ft_calloc(100 * a, sizeof(int));
	if (!dlist.cmds || a == 1 || ft_check_numeric(a, b))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	tab = ft_get_tab(a--, b);
	if (ft_check_duplicate(a, tab))
	{
		ft_putstr_fd("Error, duplicate\n", 2);
		return (0);
	}
	dlist.a = ft_create_list(a, tab);
	dlist.b = NULL;
	if (!ft_check_sort(&dlist))
		ft_sort_list(&dlist);
	free(dlist.cmds);
	ft_free_list(dlist.a);
	return (0);
}
