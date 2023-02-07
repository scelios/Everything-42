/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:35:15 by beaudibe          #+#    #+#             */
/*   Updated: 2023/02/04 21:51:59 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_list *list, int	size)
{
	t_list	*current;
	int	total;
	int	i;

	i = 0;
	total = 0;
	current = list;
	while (current != NULL && i++ < size)
	{
		total += *(int *) current->content;
		current = current->next;
	}
	return ((int)((float) total / (float) size));
}

void	ft_pb(t_dlist *dlist)
{
	t_list *first_a;

	first_a = dlist->a;
	if(first_a != NULL)
	{
		dlist->a = first_a->next;
		ft_lstadd_front(&(dlist->b), ft_lstnew(malloc(sizeof(int))));
		*((int*)dlist->b->content) = *((int*)first_a->content);
		free(first_a->content);
		free(first_a);
		//ft_putstr_fd("pb\n", 1);
		dlist->cmds[dlist->cmds_size++] = 1;
	}
}

void	ft_pa(t_dlist *dlist)
{
	t_list *first_b;

	first_b = dlist->b;
	if(first_b != NULL)
	{
		dlist->b = first_b->next;
		ft_lstadd_front(&(dlist->a), ft_lstnew(malloc(sizeof(int))));
		*((int*)dlist->a->content) = *((int*)first_b->content);
		free(first_b->content);
		free(first_b);
		//ft_putstr_fd("pa\n", 1);
		dlist->cmds[dlist->cmds_size++] = 2;
	}
}

void	ft_sa(t_dlist *dlist)
{
	int	temp;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		temp = *((int*) dlist->a->content);
		*((int*) dlist->a->content) = *((int*) dlist->a->next->content);
		*((int*) dlist->a->next->content) = temp;
		//ft_putstr_fd("sa\n", 1);
		dlist->cmds[dlist->cmds_size++] = 3;
	}
}

void	ft_sb(t_dlist *dlist)
{
	int	temp;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		temp = *((int*) dlist->b->content);
		*((int*) dlist->b->content) = *((int*) dlist->b->next->content);
		*((int*) dlist->b->next->content) = temp;
		//ft_putstr_fd("sb\n", 1);
		dlist->cmds[dlist->cmds_size++] = 4;
	}
}

void	ft_ra(t_dlist *dlist)
{
	t_list *last;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		last = ft_lstlast(dlist->a);
		last->next = dlist->a;
		dlist->a = dlist->a->next;
		last->next->next = NULL;
		//ft_putstr_fd("ra\n", 1);
		dlist->cmds[dlist->cmds_size++] = 5;
	}
}

void	ft_rb(t_dlist *dlist)
{
	t_list *last;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		last = ft_lstlast(dlist->b);
		last->next = dlist->b;
		dlist->b = dlist->b->next;
		last->next->next = NULL;
		//ft_putstr_fd("rb\n", 1);
		dlist->cmds[dlist->cmds_size++] = 6;
	}
}

void	ft_rra(t_dlist *dlist)
{
	t_list *last;
	t_list *current;
	t_list *first;

	if (dlist->a != NULL && dlist->a->next != NULL)
	{
		current = dlist->a;
		while (current->next->next != NULL)
		    current = current->next;
		last = ft_lstlast(dlist->a);
		first = dlist->a->next;
		current->next = NULL;
		last->next = dlist->a;
		dlist->a = last;
		//ft_putstr_fd("rra\n", 1);
		dlist->cmds[dlist->cmds_size++] = 7;
	}
}

void	ft_rrb(t_dlist *dlist)
{
	t_list *last;
	t_list *current;
	t_list *first;

	if (dlist->b != NULL && dlist->b->next != NULL)
	{
		current = dlist->b;
		while (current->next->next != NULL)
		    current = current->next;
		last = ft_lstlast(dlist->b);
		first = dlist->b->next;
		current->next = NULL;
		last->next = dlist->b;
		dlist->b = last;
		//ft_putstr_fd("rrb\n", 1);
		dlist->cmds[dlist->cmds_size++] = 8;
	}
}

void	ft_rr(t_dlist *dlist)
{
	ft_ra(dlist);
	ft_rb(dlist);
	//ft_putstr_fd("rr\n", 1);
	dlist->cmds[dlist->cmds_size++] = 9;
}

void	ft_rrr(t_dlist *dlist)
{
	ft_rra(dlist);
	ft_rrb(dlist);
	//ft_putstr_fd("rrr\n", 1);
	dlist->cmds[dlist->cmds_size++] = 10;
}

static int	ft_check_numeric(int a, char **b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a)
	{
		j = 0;
		if (b[i][0] == '-')
			j++;
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

static int	ft_check_duplicate(int a, int *b)
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

void	ft_free_list(t_list	*lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		lst = temp->next;
		free((int *)temp->content);
		free(temp);
		temp = lst;
	}
}

t_list	*ft_create_list(int a, int *tab)
{
	t_list	*lst;
	t_list	*temp1;
	int		i;

	temp1 = ft_lstnew(malloc(sizeof(int)));
	if (!temp1)
		return (NULL);
	*((int*)temp1->content) = tab[0];
	lst = temp1;
	i = 0;
	while (++i < a)
	{
		temp1->next = ft_lstnew(malloc(sizeof(int)));
		if (!temp1->next)
		{
			ft_free_list(lst);
			free(tab);
			return (NULL);
		}
		*((int*)temp1->next->content) = tab[i];
		temp1 = temp1->next;
	}
	free(tab);
	return (lst);
}

int	*ft_get_tab(int a, char **b)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * (a - 1));
	if (!tab)
		return (0);
	i = 0;
	while (++i < a)
		tab[i - 1] = ft_atoi(b[i]);
	return (tab);
}

void ft_print_list(t_list *lst)
{
    t_list *current = lst;
    while (current != NULL)
    {
        printf("%d ", *((int*)current->content));
        current = current->next;
    }
}

void ft_print_dlist(t_dlist *dlist)
{
    printf("List a: ");
    ft_print_list(dlist->a);
    printf("\nList b: ");
    ft_print_list(dlist->b);
	printf("\n\n");
}

int	ft_len_is_sort(t_list *list, int start_sort)
{
	t_list	*temp;
	int	i;

	temp = list;
	i = 0;
	while(temp->next && start_sort--)
	{
		i++;
		if (*(int *)temp->content > *(int *) (temp->next)->content)
			i = 0;
		temp = temp->next;
	}
	return (i);
}

int	ft_all_above_median(t_list *list, int median, int len)
{
	t_list	*temp;

	temp = list;
	while(temp && len--)
	{
		if (*(int *)temp->content < median)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_resolve_little(t_dlist *dlist)
{
	if (ft_lstsize(dlist->a) >= 2 && *(int *)dlist->a->content > *(int *) dlist->a->next->content)
		ft_sa(dlist);
}


int	*ft_first_big_sort(t_dlist *dlist)
{
	int	median;
	int		*nbr_of_group;
	int		size;
	int		i;

	dlist->size = 0;
	nbr_of_group = malloc(sizeof(int) * 10000);
	while(ft_lstsize(dlist->a) > 2)
	{
		size = ft_lstsize(dlist->a);
		median = ft_median(dlist->a, size);
		i = 0;
		while (!ft_all_above_median(dlist->a, median, size))
		{
			if (*(int *)dlist->a->content < median)
			{
				i++;
				ft_pb(dlist);
			}
			else
				ft_ra(dlist);
		}
		//printf("%f\n",median);
		//ft_print_dlist(dlist);
		nbr_of_group[dlist->size++] = i;
	}
	ft_resolve_little(dlist);
	return (nbr_of_group);
}

void	ft_push_while(t_dlist *dlist, int len, void (*f)(t_dlist *dlist))
{
	while (len--)
		f(dlist);
}


void	ft_cut_by_2_a(t_dlist *dlist, int len)
{
	int	median;
	int		nbr[10000];
	int		i;
	int		j;
	int		rotate_a;


	j = 1;
	//nbr = malloc(sizeof(int) * (ft_lstsize(dlist->b) * ft_lstsize(dlist->a)));
	while (ft_lstsize(dlist->a) > 2 + ft_len_is_sort(dlist->a, 1))
	{
		median = ft_median(dlist->a, len);
		i = 0;
		rotate_a = 0;
		while (!ft_all_above_median(dlist->a, median, len))
		{
			if (*(int *)dlist->a->content < median)
			{
				ft_pb(dlist);
				i++;
			}
			else
			{
				ft_ra(dlist);
				rotate_a++;
			}
		}
		nbr[j++] = i;
		while (rotate_a-- > 0)
			ft_rra(dlist);
		//len -= i;
	}
	nbr[0] = j;
	ft_resolve_little(dlist);
	//free(nbr);
	// while (j)
		// ft_cut_by_2_b(dlist, nbr[--j], 1);
}




int	ft_cut_by_2_b(t_dlist *dlist, int len, int test)
{
	while (len > 2)
	{
		int	median = 0;
		int	i = 0;
		int	rotate_b = 0;
		int	rotate_a = 0;
		int	j = 0;
		int temp = 0;
		int	temp2 = 0;
		int	nbr_groups = 0;
		int	groups[10000];

		i = 0;
		// if (++pop > 10)
			// return (0);
		rotate_b = 0;
		median = ft_median(dlist->b, len);
		//printf("median = %d len = %d\n", median, len);
		while (len-- > 0)
		{
			if (*(int *)dlist->b->content > median)
			{
				ft_pa(dlist);
				i++;
			}
			else
			{
				ft_rb(dlist);
				rotate_b++;
			}
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
				if (*(int *)dlist->a->content < median)
				{
					ft_pb(dlist);
					j++;
				}
				else
				{
					ft_ra(dlist);
					rotate_a++;
				}
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
			// while(groups[nbr_groups]-- > 0)
				// ft_pa(dlist);
			//ft_resolve_little(dlist);
		}
		ft_resolve_little(dlist);
		len = rotate_b;
		//printf("rotate_b = %d\n",rotate_b);
		//ft_print_dlist(dlist);
	}
	while (len-- > 0){
		//ft_resolve_little(dlist);
		ft_pa(dlist);
		ft_resolve_little(dlist);
	}

	return (0);
}


void ft_print_cmd(int *list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (list[i] == 1)
			ft_putstr_fd("pb\n",1);
		else if (list[i] == 2)
			ft_putstr_fd("pa\n",1);
		else if (list[i] == 3)
			ft_putstr_fd("sa\n",1);
		else if (list[i] == 4)
			ft_putstr_fd("sb\n",1);
		else if (list[i] == 5)
			ft_putstr_fd("ra\n",1);
		else if (list[i] == 6)
			ft_putstr_fd("rb\n",1);
		else if (list[i] == 7)
			ft_putstr_fd("rra\n",1);
		else if (list[i] == 8)
			ft_putstr_fd("rrb\n",1);
		else if (list[i] == 9)
			ft_putstr_fd("rr\n",1);
		else if (list[i] == 10)
			ft_putstr_fd("rrr\n",1);
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_nbr_0(t_dlist *dlist, int i)
{
	int	j;

	j = 0;
	while (dlist->cmds[++i] == 0)
		j++;
	return (j + 1);
}

void	ft_check_cmd(t_dlist *dlist)
{
	int	i;
	int j;

	j = 1;
	while (j != 0)
	{
		j = 0;
		i = -1;
		while (++i < dlist->cmds_size - 1)
		{
			if ((dlist->cmds[i] == 5 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 7)
			|| (dlist->cmds[i] == 7 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 5)\
			|| (dlist->cmds[i] == 6 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 8)\
			|| (dlist->cmds[i] == 8 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 6)\
			|| (dlist->cmds[i] == 2 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 1)\
			|| (dlist->cmds[i] == 1 && dlist->cmds[i + ft_nbr_0(dlist, i)] == 2))
			{
				dlist->cmds[i] = 0;
				dlist->cmds[i + ft_nbr_0(dlist, i)] = 0;
				i++;
				j++;
			}
		}
	}
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

int	ft_lstmax(t_list *list)
{
	int	max;

	max = *(int *) list->content;
	while (list)
	{
		if (*(int *) list->content > max)
			max = *(int *) list->content;
		list = list->next;
	}
	return (max);
}

int	ft_lstmin(t_list *list)
{
	int	min;

	min = *(int *) list->content;
	while (list)
	{
		if (*(int *) list->content < min)
			min = *(int *) list->content;
		list = list->next;
	}
	return (min);
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
		if (ft_lstmax(dlist->a) == *(int *) dlist->a->content && ft_lstmin(dlist->a) != *(int *) dlist->a->next->content)
		{
			ft_pb(dlist);
			ft_ra(dlist);
		}
		else if(ft_lstmax(dlist->a) != *(int *) dlist->a->content && *(int *) dlist->a->content > *(int *) dlist->a->next->content)
		{
			ft_pb(dlist);
			ft_ra(dlist);
		}
		//ft_print_dlist(dlist);
	}

	while (ft_is_sort(dlist->a)){
		//ft_print_dlist(dlist);
		ft_ra(dlist);
	}
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

void	ft_sort_list(t_dlist *dlist)
{
	int	*nbr_of_group;

	if (ft_lstsize(dlist->a) <= 5)
		ft_little(dlist);
	else
	{
		nbr_of_group = ft_first_big_sort(dlist);
		while (--dlist->size >= 0){
			//printf("nbr_of_group[dlist->size] = %d\n",nbr_of_group[dlist->size]);
			ft_cut_by_2_b(dlist, nbr_of_group[dlist->size], dlist->size > 0);
		}
		free(nbr_of_group);
	}
	ft_check_cmd(dlist);
	ft_print_cmd(dlist->cmds, dlist->cmds_size);
	//ft_print_dlist(dlist);
}


int	main(int a, char **b)
{
	t_dlist	dlist;
	t_dlist	temp;
	int		*tab;

	dlist.cmds_size = 0;
	if (a == 2)
		return (0);
	dlist.cmds = ft_calloc(100 * a, sizeof(int));
	if (!dlist.cmds || a == 1 || ft_check_numeric(a, b))
	{
		ft_putstr_fd("Error1\n", 2);
		return (0);
	}
	tab = ft_get_tab(a--, b);
	if (ft_check_duplicate(a, tab))
	{
		ft_putstr_fd("Error2\n",2);
		return (0);
	}
	dlist.a = ft_create_list(a, tab);
	dlist.b = NULL;
	ft_sort_list(&dlist);

	// printf("is sort = %d\n", ft_is_sort(dlist.a));
	//printf("min = %d\n", ft_lstmin(dlist.a));
	free(dlist.cmds);
	ft_free_list(dlist.a);
	//ft_free_list(dlist.b);
	//system("leaks push_swap");
	//return (0);
	exit(0);
}
