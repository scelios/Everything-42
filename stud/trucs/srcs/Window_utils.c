/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:45:26 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/26 14:39:03 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void) xdelta;
	fractol = (t_fractol *) param;
	if (ydelta > 0)
		fractol->zoom = 1.25;
	else if (ydelta < 0)
		fractol->zoom = 0.75;
}

void	ft_close_hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void	ft_mouse_hook(mouse_key_t button, \
	action_t action, modifier_key_t mods, void *param)
{
	t_fractol	*fractol;

	(void) mods;
	fractol = (t_fractol *) param;
	if (action == MLX_PRESS)
		shutdown("click");
	/*if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		fractol->zoom = 0.75;
		fractol->go[1] = 1;
	}
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		fractol->go[2] = 1;
		fractol->go[1] = 1;
	}
	fractol->go[0] = 1;*/
}

void	ft_calcul_cube_rectangle(t_fractol *fractol, \
		double x[2], double y[2], double new_size[5])
{
	double	k[2];
	double	l[2];

	k[0] = x[0] + new_size[0];
	k[1] = x[1] - new_size[0];
	l[0] = y[0] + new_size[1];
	l[1] = y[1] - new_size[1];
	ft_draw_rectangle(fractol, k, l, new_size[2] * 10);
}

void	ft_calcul_cube(t_fractol *fractol, double x[2], \
		double y[2], double new_size[5])
{
	double	k[2];
	double	l[2];

	k[0] = x[0] + new_size[0] * new_size[3];
	k[1] = x[0] + new_size[0] * (new_size[3] + 1);
	l[0] = y[0] + new_size[1] * new_size[4];
	l[1] = y[0] + new_size[1] * (new_size[4] + 1);
	ft_cube(fractol, k, l, new_size[2] - 1);
}
