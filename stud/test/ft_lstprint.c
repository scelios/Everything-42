/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:53:25 by beaudibe          #+#    #+#             */
/*   Updated: 2022/10/03 15:35:05 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		ft_putstr_fd((char *)current->content, 1);
		current = current->next;
	}
}
