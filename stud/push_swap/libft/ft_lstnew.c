/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:05:41 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/19 14:22:16 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = malloc(sizeof(str));
	if (!str)
		return (0);
	str->content = content;
	str->next = 0;
	return (str);
}
