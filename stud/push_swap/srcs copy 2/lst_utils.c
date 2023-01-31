/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:34:11 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/18 17:25:14 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
t_list_int	*ft_lstnew_int(int content)
{
	t_list_int	*str;

	str = malloc(sizeof(str));
	if (!str)
		return (0);
	str->content = content;
	str->next = 0;
	return (str);
}

t_list_int	*ft_lstlast_int(t_list_int *lst)
{
	int			i;
	t_list_int	*cur;

	cur = lst;
	i = ft_lstsize_int(lst);
	if (!i)
		return (lst);
	while (--i)
		cur = cur->next;
	return (cur);
}

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast_int(*lst)->next = new;
}

int	ft_lstsize_int(t_list_int *lst)
{
	int			i;
	t_list_int	*cur;

	cur = lst;
	i = 0;
	while (cur && ++i)
		cur = cur->next;
	return (i);
}
*/
