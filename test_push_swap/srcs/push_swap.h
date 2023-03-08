/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:19:20 by beaudibe          #+#    #+#             */
/*   Updated: 2023/02/07 10:58:14 by beaudibe         ###   ########.fr       */
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
	int			*cmds;
	int			cmds_size;
	//int		median[100][100];
}	t_dlist;

typedef struct s_list_group
{
	t_list	*list;
	void	(*ft_p)(t_dlist *dlist);
	void	(*ft_r)(t_dlist *dlist);
}	t_list_groups;

void	ft_sort_tab(t_dlist *dlist);

int	ft_median(t_list *list, int size);

int	ft_is_sort(t_list *list);

int	ft_cut_by_2_b(t_dlist *dlist, int len, int test);
#endif
