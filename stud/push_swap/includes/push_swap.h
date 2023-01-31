/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:19:20 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/31 11:13:34 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdio.h"
# include "../libft/includes/libft.h"

typedef struct s_group
{
	int		min;
	int		max;
	int		size;
}	t_groups;



typedef struct s_double_list
{
	t_list		*a;
	t_list		*b;
	t_groups	groups[500];
	int			size;
	//int		median[100][100];
}	t_dlist;

typedef struct s_list_group
{
	t_list	*list;
	void	(*ft_p)(t_dlist *dlist);
	void	(*ft_r)(t_dlist *dlist);
}	t_list_groups;

void	ft_sort_tab(t_dlist *dlist);

double	ft_median(t_list *list, int size);

int	ft_is_sort(t_list *list);

int	ft_cut_by_2_b(t_dlist *dlist, int len, int test);
#endif

/*
//ft_cut_by_2(t_dlist *dlist, t_groups median)
// t_groups	little_median[100];
int	i;
int j;

i = 0;
if (size == 2 || size == 1)
{
	if (size == 2)
	{
		ft_pa(dlist);
		ft_pa(dlist);
		ft_resolve_little(dlist);
	}
	else
		ft_pa(dlist);
	return ;
}
// Tant que median.size > 2 :
	// - tant que les elements de b ne sont pas tous en dessous de la mediane
		// - si le premier element de la liste b est plus grand que la mediane
			// on actualise min et max et size de little_median[i]
			// - on le push dans la liste a
			// - on incremente push_a
		// - sinon
			// - on rotate la liste b
			// - on incremente rotate_b
		// - on incremente la liste b
	// i++;
	// - len /= 2
	// - on reverse rotate la liste b rotate_b fois
// - tant que len_a > 2
	// - tant que les elements de a ne sont pas tous au dessus de la mediane
		// si le premier element de la liste a est plus petit que la mediane
			// on actualise min et max et size
			// - on le push dans la liste b
			// - on incremente push_b
		// - sinon
			// - on rotate la liste a
			// - on incremente rotate_a
		// - on incremente la liste a
	// - len_a /= 2
	// - on reverse rotate la liste a rotate_a fois



void	ft_cut_by_2(t_dlist *dlist, t_groups median)
{

}


void	ft_first_big_sort(t_dlist *dlist, t_list *list, void (*ft_p)(t_dlist *dlist), void (*ft_r)(t_dlist *dlist))
{
	double	median;
	int		size;
	int	i;
	int	j;

	dlist->size = 0;
	size = ft_lstsize(list);
	while(ft_lstsize(list) > 2)
	{
		median = ft_median(list, size);

		i = 0;
		j = 0;
		while (!ft_all_above_median(list, median))
		{
			if (*(int *)list->content < median)
			{
				i++;
				ft_is_min_or_max(dlist, dlist->size, *(int *)list->content);
				ft_p(dlist);
			}
			else
			{
				j++;
				ft_r(dlist);
			}
		}
		dlist->median[dlist->size++].size = i;
	}
}

*/

