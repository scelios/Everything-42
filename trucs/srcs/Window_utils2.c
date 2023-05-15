/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:46:14 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/26 14:37:16 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

void	ft_calcul_zoom(t_fractol *fractol, double x_center, double y_center)
{
	double	x_size;
	double	y_size;

	x_size = (fractol->xmax - fractol->xmin) * fractol->zoom;
	y_size = (fractol->ymax - fractol->ymin) * fractol->zoom;
	fractol->xmin = x_center - x_size / 2 + (fractol->x_offset * x_size);
	fractol->xmax = x_center + x_size / 2 + (fractol->x_offset * x_size);
	fractol->ymin = y_center - y_size / 2 + (fractol->y_offset * y_size);
	fractol->ymax = y_center + y_size / 2 + (fractol->y_offset * y_size);
	fractol->zoom = 1;
	fractol->x_offset = 0;
	fractol->y_offset = 0;
	fractol->go[0] = 1;
	fractol->go[2] = 0;
	fractol->go[1] = 0;
}

void	ft_zoom_move(t_fractol	*fractol)
{
	double	x_center;
	double	y_center;

	if (fractol->zoom == 1 && !fractol->x_offset \
		&& !fractol->y_offset && !fractol->go[2])
		return ;
	x_center = (fractol->xmin + fractol->xmax) / 2;
	y_center = (fractol->ymin + fractol->ymax) / 2;
	if (fractol->fractal[1])
	{
		fractol->x_offset = -fractol->x_offset;
		fractol->y_offset = -fractol->y_offset;
		if (fractol->zoom == 1.25)
			fractol->zoom = 0.75;
		else if (fractol->zoom == 0.75)
			fractol->zoom = 1.25;
	}
	if (fractol->go[1])
	{
		x_center = fractol->xmin + (fractol->mousex / fractol->width) \
			* (fractol->xmax - fractol->xmin);
		y_center = fractol->ymin + (fractol->mousey / fractol->height) \
			* (fractol->ymax - fractol->ymin);
	}
	ft_calcul_zoom(fractol, x_center, y_center);
}

void	ft_cursor(double xpos, double ypos, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	static double	x;
	static double	y;
	if (x == 0 && y == 0)
	{
		x = xpos;
		y = ypos;
	}
	if (x != xpos || y != ypos)
		shutdown("Mouse moved\n");
	fractol->mousex = xpos;
	fractol->mousey = ypos;
}

void	display_fractal(t_fractol *fractol)
{
	double	x[2];
	double	y[2];
	double	j[2];
	double	i[2];

	x[0] = fractol->xmin;
	x[1] = fractol->xmax;
	y[0] = fractol->ymin;
	y[1] = fractol->ymax;
	i[0] = 0;
	i[1] = fractol->height - 1;
	j[0] = 0;
	j[1] = fractol->width - 1;
	ft_draw_rectangle(fractol, j, i, 255);
	ft_zoom_move(fractol);
	ft_cube(fractol, x, y, fractol->max_iteration);
}

void	ft_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;

	time_t current_time;
	struct tm *time_info;
	time(&current_time);
	time_info = localtime(&current_time);
	if (time_info->tm_hour == fractol->hour)
    	shutdown("Heure de fermeture\n");


	/*t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	ft_zoom_move(fractol);
	if (!fractol->go[0] && !fractol->mouse_c && !fractol->julia)
		return ;
	fractol->go[0] = 0;
	if (fractol->fractal[1])
	{
		display_fractal(fractol);
		return ;
	}
	ft_mandelbrot_julia(fractol, 0, 0, 0.0);*/
}
