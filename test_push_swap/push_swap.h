/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:36:55 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/16 17:14:41 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdio.h"
# include "libft/includes/libft.h"

typedef struct s_truc
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
}	t_truc;

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
}	t_dlist;

typedef struct s_list_group
{
	t_list	*list;
	void	(*ft_p)(t_dlist *dlist);
	void	(*ft_r)(t_dlist *dlist);
}	t_list_groups;

t_list	*ft_create_list(int a, int *tab);

void	ft_check_cmd(t_dlist *dlist);
void	ft_free_list(t_list	*lst);
void	ft_cut_by_2_a(t_dlist *dlist, int len);
void	ft_sort_tab(t_dlist *dlist);
void	ft_little(t_dlist *dlist);
void	ft_solve5(t_dlist *dlist);
void	ft_solve3(t_dlist *dlist);
void	ft_resolve_little(t_dlist *dlist);
void	ft_print_cmd(int *list, int size);
void	ft_ra(t_dlist *dlist);
void	ft_sb(t_dlist *dlist);
void	ft_sa(t_dlist *dlist);
void	ft_pa(t_dlist *dlist);
void	ft_pb(t_dlist *dlist);
void	ft_rb(t_dlist *dlist);
void	ft_rra(t_dlist *dlist);
void	ft_rrb(t_dlist *dlist);
void	ft_rr(t_dlist *dlist);
void	ft_rrr(t_dlist *dlist);
void	ft_cut_by_2_a(t_dlist *dlist, int len);
void	ft_resolve_little(t_dlist *dlist);
void	ft_solve3(t_dlist *dlist);
void	ft_solve5(t_dlist *dlist);
void	ft_little(t_dlist *dlist);
void	ft_sort_list(t_dlist *dlist);
void	ft_push_while(t_dlist *dlist, int len, void (*f)(t_dlist *dlist));

int		ft_min(int a, int b);
int		ft_check_numeric(int a, char **b);
int		ft_check_duplicate(int a, int *b);
int		ft_if(t_dlist *dlist, int i);
int		ft_nbr_0(t_dlist *dlist, int i);
int		*ft_get_tab(int a, char **b);
int		ft_cut_by_2_b(t_dlist *dlist, int len, int test);
int		*ft_first_big_sort(t_dlist *dlist);
int		ft_median(t_list *list, int size);
int		ft_is_sort(t_list *list);
int		ft_cut_by_2_b(t_dlist *dlist, int len, int test);
int		ft_len_is_sort(t_list *list, int start_sort);
int		ft_all_above_median(t_list *list, int median, int len);
int		ft_lstmax(t_list *list);
int		ft_lstmin(t_list *list);
int		*ft_first_big_sort(t_dlist *dlist);
int		ft_cut_by_2_b(t_dlist *dlist, int len, int test);

float	ft_how_much_sort(t_list *list);

#endif
