/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:29:31 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/14 11:24:06 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static t_byte	g_list;

static void	ft_reset_static(void)
{
	g_list.str = NULL;
	g_list.i = 0;
}

static void	ft_get_char(int sig_id)
{
	static int				bites;
	static size_t			i;
	static unsigned char	c;

	bites++;
	c |= sig_id == SIGUSR2;
	if (bites == 8)
	{
		g_list.str[i++] = c;
		if (!c)
		{
			ft_putstr_fd(g_list.str, 1);
			free(g_list.str);
			ft_reset_static();
			i = 0;
		}
		bites = 0;
		c = 0;
	}
	else
		c <<= 1;
}

static size_t	ft_get_len(int sig_id)
{
	static size_t	len_str;

	if (g_list.i == 1)
		len_str = 0;
	len_str |= sig_id == SIGUSR2;
	if (g_list.i == 64)
		return (len_str);
	else
		len_str <<= 1;
	return (0);
}

static void	ft_receive_byte(int sig_id, siginfo_t *info, void *context)
{
	size_t	len_str;

	(void) context;
	g_list.i++;
	if (g_list.i < 65)
	{
		len_str = ft_get_len(sig_id);
		if (g_list.i == 64)
		{
			g_list.str = malloc (len_str + 1);
			if (!g_list.str)
			{
				ft_putstr_fd("Error malloc\n", 1);
				return ;
			}
		}
	}
	else
		ft_get_char(sig_id);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = ft_receive_byte;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("The PID of the server is: %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
