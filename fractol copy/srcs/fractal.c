/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:58:36 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/18 12:07:06 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_fractol *fractol, double temp[2])
{
	static double	test[2];

	if (fractol->julia || fractol->fractal[2])
	{
		test[0] = -0.8;
		test[1] = 0.156;
		if (fractol->fractal[2])
		{
			test[0] = fractol->mousex;
			test[1] = fractol->mousey;
		}
	}
	else
	{
		test[0] = 3 * (fractol->mousex - \
		(fractol->height / 2)) / fractol->height;
		test[1] = 3 * (fractol->mousey - \
		(fractol->width / 2)) / fractol->width ;
	}
	temp[0] = test[0];
	temp[1] = test[1];
}

int	ft_get_iteration(t_fractol *fractol, double zx, double zy, double temp[2])
{
	double	zx2;
	double	zy2;
	int		iteration;

	if (fractol->mouse_c || fractol->julia)
		ft_julia(fractol, temp);
	else if (fractol->fractal[0])
	{
		temp[0] = zx;
		temp[1] = zy;
		zx = 0;
		zy = 0;
	}
	zx2 = zx * zx;
	zy2 = zy * zy;
	iteration = 0;
	while (++iteration < fractol->max_iteration && ((zx2 + zy2) < 4.0))
	{
		zy = 2 * zx * zy + temp[1];
		zx = zx2 - zy2 + temp[0];
		zx2 = zx * zx;
		zy2 = zy * zy;
	}
	return (iteration);
}

void	ft_mandelbrot_julia(t_fractol *fractol, int x, int y, double zx)
{
	double			zy;
	static double	temp[2];
	int				iteration;

	y = 0;
	while (y++ < fractol->height - 1)
	{
		zy = fractol->ymin + y * \
			((fractol->ymax - fractol->ymin) / fractol->height);
		x = 0;
		while (x++ < fractol->width - 1)
		{
			zx = fractol->xmin + x * \
				((fractol->xmax - fractol->xmin) / fractol->width);
			iteration = ft_get_iteration(fractol, zx, zy, temp);
			if (iteration == fractol->max_iteration)
				mlx_put_pixel(fractol->img, x, y, get_rgba(0, 0, 0, 255));
			else
				mlx_put_pixel(fractol->img, x, y, \
				get_rgba((3 * (iteration + fractol->color)) % 256, \
				(5 * (iteration + fractol->color)) % 256, \
				(2 * (iteration + fractol->color)) % 256, 255));
		}
	}
}

void	ft_draw_rectangle(t_fractol *fractol, double x[2], \
		double y[2], int color)
{
	int		i[2];
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;

	x_min = fmax(0, x[0]);
	y_min = fmax(0, y[0]);
	y_max = fmin(fractol->height - 1, y[1]);
	x_max = fmin(fractol->width - 1, x[1]);
	i[0] = y_min - 1;
	while (++i[0] < y_max)
	{
		i[1] = x_min - 1;
		while (++i[1] < x_max)
		{
			mlx_put_pixel(fractol->img, i[1], i[0], \
			get_rgba((3 * (color + fractol->color)) % 256, \
				(5 * (color + fractol->color)) % 256, \
				(2 * (color + fractol->color)) % 256, 255));
		}
	}
}

void	ft_cube(t_fractol *fractol, double x[2], double y[2], int depth)
{
	double	new_size[5];
	int		i;
	int		j;

	if (!depth)
		return ;
	ft_draw_rectangle(fractol, x, y, 255);
	i = -1;
	new_size[0] = (x[1] - x[0]) / 3;
	new_size[1] = (y[1] - y[0]) / 3;
	new_size[2] = depth;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			new_size[3] = i;
			new_size[4] = j;
			if (i == 1 && j == 1)
				ft_calcul_cube_rectangle(fractol, x, y, new_size);
			else
				ft_calcul_cube(fractol, x, y, new_size);
		}
	}
}
