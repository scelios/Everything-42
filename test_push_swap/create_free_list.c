/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:57:13 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/09 16:00:37 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	*((int *)temp1->content) = tab[0];
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
		*((int *)temp1->next->content) = tab[i];
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
