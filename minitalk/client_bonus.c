/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:33:05 by beaudibe          #+#    #+#             */
/*   Updated: 2022/12/13 18:19:07 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk_bonus.h"

static t_send	g_wait;

void	ft_wait_str(int i)
{
	g_wait.wait = i;
}

static int	ft_send(int pid, size_t c, int i)
{
	static int	timer;

	g_wait.wait = 0;
	if (c >> (i - (++timer)) & 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Error, I am unable to send SIGUSR1\n", 35);
			exit (1);
		}
	}
	while (!g_wait.wait)
		;
	usleep (20 + g_wait.time / 1000);
	if (timer == i)
	{
		timer = 0;
		return (1);
	}
	return (0);
}

static int	ft_error(int argc, int pid)
{
	if (argc != 3)
		write(1, "Utilisation: ./client [PID_SERVER] \"Message\"\n", 45);
	if (pid <= 0)
		write(1, "Pid_server: number write with [0-9]\n", 36);
	return (0);
}

int	main(int argc, char **b)
{
	int					pid;
	static int			first;
	int					end;
	int					i;

	end = 0;
	i = 0;
	first = 0;
	if (argc == 3)
		pid = ft_atoi(b[1]);
	if (argc != 3 || pid <= 0)
		exit(ft_error(argc, pid));
	signal(SIGUSR2, ft_wait_str);
	g_wait.time = ft_strlen(b[2]);
	while (!end)
	{
		if (!first && ft_send(pid, g_wait.time, 64))
			first = 1;
		else if (first && b[2][i] && ft_send (pid, (size_t) b[2][i], 8))
			i++;
		else if (!b[2][i] && ft_send(pid, 0, 8))
			end = 1;
	}
	return (0);
}
