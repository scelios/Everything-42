/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:35:15 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/25 21:50:22 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	ft_median(t_list *list, int	size)
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
	return ((float) total / (float) size);
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
		ft_putstr_fd("pb\n", 1);
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
		ft_putstr_fd("pa\n", 1);
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
		ft_putstr_fd("sa\n", 1);
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
		ft_putstr_fd("sb\n", 1);
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
		ft_putstr_fd("ra\n", 1);
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
		ft_putstr_fd("rb\n", 1);
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
		ft_putstr_fd("rra\n", 1);
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
		ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rr(t_dlist *dlist)
{
	ft_ra(dlist);
	ft_rb(dlist);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_dlist *dlist)
{
	ft_rra(dlist);
	ft_rrb(dlist);
	ft_putstr_fd("rrr\n", 1);
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

	if (!start_sort)
		return (0);
	temp = list;
	i = 0;
	while(temp->next)
	{
		i++;
		if (*(int *)temp->content > *(int *) (temp->next)->content)
			i = 0;
		temp = temp->next;
	}
	return (i);
}

int	ft_all_above_median(t_list *list, double median, int len)
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
	if (ft_lstsize(dlist->a) >= 1 && *(int *)dlist->a->content > *(int *) dlist->a->next->content)
		ft_sa(dlist);
}


int	*ft_first_big_sort(t_dlist *dlist)
{
	double	median;
	int		*nbr_of_group;
	int		size;
	int		i;

	dlist->size = 0;
	nbr_of_group = malloc(sizeof(int) * 100);
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
		printf("i = %d %d\n", dlist->size - 1, i);
	}
	ft_resolve_little(dlist);
	return (nbr_of_group);
}

void	ft_push_while(t_dlist *dlist, int len, void (*f)(t_dlist *dlist))
{
	while (len--)
		f(dlist);
}

/*int	ft_cut_by_2_b(t_dlist *dlist, int len)
{
	double	median;
	int		i;
	int		rotate_b;

	i = 0;
	rotate_b = 0;
	median = ft_median(dlist->b, len);
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
	while (rotate_b--)
		ft_rrb(dlist);
	return (i);
}*/

int	ft_cut_by_2_b(t_dlist *dlist, int len)
{
	double	median;
	int		i;
	int		rotate_b;

	i = 0;
	rotate_b = 0;
	median = ft_median(dlist->b, len);
	while (len--)
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
	while (rotate_b--)
		ft_rrb(dlist);
	return (i);
}

/*int	*ft_cut_by_2_a(t_dlist *dlist, int len, int *nbr)
{
	double	median;
	int		i;
	int		j;
	int		rotate_a;


	j = 1;
	while (len > 2)
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
		len /= 2;
	}
	nbr[0] = j;
	ft_resolve_little(dlist);
	return (nbr);
}*/

int	*ft_cut_by_2_a(t_dlist *dlist, int len, int *nbr)
{
	double	median;
	int		i;
	int		j;
	int		rotate_a;


	j = 1;
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
	}
	nbr[0] = j;
	ft_resolve_little(dlist);
	return (nbr);
}

void	ft_solve(t_dlist *dlist, int len)
{
	int	*nbr_of_group;
	int	len_group;
	int	i;

	nbr_of_group = malloc(sizeof(int) * 100);
	if (!nbr_of_group)
		return ;
	while (len > 1)
	{
		len_group = ft_cut_by_2_b(dlist, len);
		// if (len_group >= 2)
			// ft_resolve_little(dlist);
		nbr_of_group = ft_cut_by_2_a(dlist, len_group, nbr_of_group);
		i = -1;
		while (++i > nbr_of_group[0])
			ft_solve(dlist, ++nbr_of_group[nbr_of_group[0] - i]);
		len -= len_group;
	}
	ft_push_while(dlist, len, &ft_pa);
	free(nbr_of_group);
}

void	ft_sort_list(t_dlist *dlist)
{
	int	*nbr_of_group;

	nbr_of_group = ft_first_big_sort(dlist);
	//dlist->size++;
	while (--dlist->size >= 0)
		ft_solve(dlist, nbr_of_group[dlist->size]);
	// while (dlist->b)
		// ft_solve(dlist, ft_lstsize(dlist->b));
	//printf("group = %d %d\n", nbr_of_group[dlist->size] ,dlist->size);
	//ft_solve(dlist, nbr_of_group[--dlist->size]);
	//}
	free(nbr_of_group);

}

int	main(int a, char **b)
{
	t_dlist	dlist;
	t_dlist	temp;
	int		*tab;

	if (a == 1 || ft_check_numeric(a, b))
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
	ft_print_dlist(&dlist);
	ft_sort_list(&dlist);
	ft_print_dlist(&dlist);
	ft_free_list(dlist.a);
	//ft_free_list(dlist.b);
	//system("leaks push_swap");
	//return (0);
	exit(0);
}
