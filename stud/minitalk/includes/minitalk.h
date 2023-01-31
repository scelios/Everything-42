/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:41:53 by beaudibe          #+#    #+#             */
/*   Updated: 2022/12/13 18:25:42 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include "signal.h"

typedef struct s_byte
{
	size_t			i;
	char			*str;
}	t_byte;

typedef struct s_send
{
	int	wait;
	int	time;
}	t_send;

#endif
