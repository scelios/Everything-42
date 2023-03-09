/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:28 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:45 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr_0(t_dlist *dlist, int i)
{
	int	j;

	j = 0;
	while (dlist->cmds[++i] == 0)
		j++;
	return (j + 1);
}

void	ft_print_cmd(int *list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (list[i] == 1)
			ft_putstr_fd("pb\n", 1);
		else if (list[i] == 2)
			ft_putstr_fd("pa\n", 1);
		else if (list[i] == 3)
			ft_putstr_fd("sa\n", 1);
		else if (list[i] == 4)
			ft_putstr_fd("sb\n", 1);
		else if (list[i] == 5)
			ft_putstr_fd("ra\n", 1);
		else if (list[i] == 6)
			ft_putstr_fd("rb\n", 1);
		else if (list[i] == 7)
			ft_putstr_fd("rra\n", 1);
		else if (list[i] == 8)
			ft_putstr_fd("rrb\n", 1);
	}
}
