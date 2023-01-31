/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:43:35 by beaudibe          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:05 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *s)
{
	int	i;
	int	j;

	i = -1;
	if (!s[0])
		return ((char *) str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == s[j] && str[i + j])
			j++;
		if (s[j] == '\0')
			return ((char *) str + i);
	}
	return (NULL);
}
