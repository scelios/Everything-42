/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:06 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/18 12:36:52 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(char *b)
{
	int		i;
	double	nbr[3];

	nbr[2] = 1.;
	i = -1;
	if (b[0] == '-')
		nbr[2] = -1. + ++i;
	nbr[0] = 0;
	while (b[++i])
	{
		if (b[i] == '.')
		{
			nbr[1] = 1;
			while (ft_isdigit(b[++i]))
				nbr[0] += (b[i] - '0') / pow(10, nbr[1]++);
			if (b[i] != '\0')
				return (571);
			break ;
		}
		else if (ft_isdigit(b[i]))
			nbr[0] = (10 * nbr[0]) + b[i] - '0';
		else
			return (-571.123);
	}
	return (nbr[0] * nbr[2]);
}

int	ft_get_julia(t_fractol *fractol, char **b)
{
	fractol->mousex = ft_atof(b[1]);
	fractol->mousey = ft_atof(b[2]);
	if (fractol->mousex == -571.123 || fractol->mousey == -571.123)
	{
		ft_putstr_fd("Usage: Mandelbrot ou Julia ou 0.25 0.0\n", 1);
		return (0);
	}
	fractol->fractal[2] = 1;
	fractol->julia = 1;
	return (1);
}

int	ft_choose(t_fractol *fractol, int a, char **b)
{
	if (a == 3)
		return (ft_get_julia(fractol, b));
	if (a == 2 && ft_strlen(b[1]) == 10 && !ft_strncmp("Mandelbrot", b[1], 10))
		return (1);
	else if (a == 2 && ft_strlen(b[1]) == 5 && !ft_strncmp("Julia", b[1], 5))
	{
		fractol->fractal[0] = 0;
		fractol->julia = 1;
		return (1);
	}
	else if (a == 2 && ft_strlen(b[1]) == 4 && !ft_strncmp("Cube", b[1], 4))
	{
		fractol->fractal[0] = 0;
		fractol->julia = 0;
		fractol->fractal[1] = 1;
		fractol->max_iteration = 3;
		fractol->xmin = 0;
		fractol->ymin = 0;
		fractol->xmax = fractol->width - 1;
		fractol->ymax = fractol->height - 1;
		return (1);
	}
	ft_putstr_fd("Usage: Mandelbrot ou Julia ou 0.25 0.0\n", 1);
	return (0);
}

int	ft_init(t_fractol *fractol, int a, char **b)
{
	fractol->width = 500;
	fractol->height = 500;
	fractol->zoom = 1;
	fractol->xmin = -2.5;
	fractol->xmax = 1.5;
	fractol->ymin = -2.0;
	fractol->ymax = 2.0;
	fractol->mouse_c = 0;
	fractol->x_offset = 0;
	fractol->y_offset = 0;
	fractol->go[0] = 1;
	fractol->go[1] = 0;
	fractol->go[2] = 0;
	fractol->max_iteration = 100;
	fractol->color = 0;
	fractol->fractal[0] = 1;
	return (ft_choose(fractol, a, b));
}

int	main(int a, char **b)
{
	t_fractol	fractol;

	if (!ft_init(&fractol, a, b))
		return (0);
	fractol.mlx = mlx_init(fractol.width, fractol.height, "fractol", true);
	if (!fractol.mlx)
		exit(EXIT_FAILURE);
	fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	mlx_scroll_hook(fractol.mlx, &ft_scrollhook, &fractol);
	mlx_key_hook(fractol.mlx, &ft_keyhook_start, &fractol);
	mlx_cursor_hook(fractol.mlx, &ft_cursor, &fractol);
	mlx_loop_hook(fractol.mlx, &ft_hook, &fractol);
	mlx_resize_hook(fractol.mlx, &ft_resize, &fractol);
	mlx_mouse_hook(fractol.mlx, &ft_mouse_hook, &fractol);
	mlx_loop(fractol.mlx);
	mlx_delete_image(fractol.mlx, fractol.img);
	mlx_terminate(fractol.mlx);
	return (0);
}
