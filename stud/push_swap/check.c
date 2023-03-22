/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:49:23 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/16 17:21:37 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_numeric(int a, char **b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a)
	{
		j = 0;
		if (b[i][0] == '-')
		{
			if (b[i][1] < '0' || b[i][1] > '9')
				return (1);
			j++;
		}
		if (ft_strlen(b[i] + j) >= 10 && ft_strncmp(b[i] + j, "2147483647", 10))
			return (1);
		while (b[i][j])
		{
			if (!ft_isdigit(b[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_check_duplicate(int a, int *b)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a)
	{
		j = i;
		while (++j < a)
		{
			if (b[i] == b[j])
				return (1);
		}
	}
	return (0);
}

int	ft_if(t_dlist *dlist, int i)
{
	if ((dlist->cmds[i] == 5 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 7) \
	|| (dlist->cmds[i] == 7 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 5) \
	|| (dlist->cmds[i] == 6 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 8) \
	|| (dlist->cmds[i] == 8 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 6) \
	|| (dlist->cmds[i] == 2 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 1) \
	|| (dlist->cmds[i] == 1 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 2))
		return (1);
	return (0);
}

void	ft_check_cmd(t_dlist *dlist)
{
	int	i;
	int	j;

	j = 1;
	while (j != 0)
	{
		j = 0;
		i = -1;
		while (++i < dlist->cmds_size - 1)
		{
			if (ft_if(dlist, i))
			{
				dlist->cmds[i] = 0;
				dlist->cmds[i + ft_nbr_0(dlist, i)] = 0;
				i++;
				j++;
			}
		}
	}
}
