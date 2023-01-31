/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:44:49 by beaudibe          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:25 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/*
int main()
{
	char *s = "      split       this for   me  !       ";
 	char **result = ft_split(s, ' ');
	int i = -1;
	while (result[++i])
		printf("%s",result[i]);
	return 0;
}*/

int	check(int i)
{
	return i;
}
int main(void)
{
	t_list * l =  NULL; t_list * l2 =  NULL;
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	/* 1 */ check(l->content == (void*)1);
	/* 2 */ check(l->next == 0);

	ft_lstadd_back(&l, ft_lstnew((void*)2));
	/* 3 */ check(l->content == (void*)1);
	/* 4 */ check(l->next->content == (void*)2);
	/* 5 */ check(l->next->next == 0);

	ft_lstadd_back(&l2, ft_lstnew((void*)3));
	ft_lstadd_back(&l2, ft_lstnew((void*)4));
	ft_lstadd_back(&l, l2);
	/* 6 */ check(l->content == (void*)1);
	/* 7 */ check(l->next->content == (void*)2);
	/* 8 */ check(l->next->next->content == (void*)3);
	/* 9 */ check(l->next->next->next->content == (void*)4);
	/* 10 */ check(l->next->next->next->next == 0);
	write(1, "\n", 1);
	return (0);
}
