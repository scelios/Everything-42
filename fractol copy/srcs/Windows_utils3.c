/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Windows_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:27:32 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/18 12:26:24 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) param;
	mlx_delete_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, width, height);
	if (!fractol->img)
		exit(EXIT_FAILURE);
	fractol->width = width;
	fractol->height = height;
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
	if (fractol->fractal[1])
	{
		fractol->xmin = 0;
		fractol->ymin = 0;
		fractol->xmax = fractol->width - 1;
		fractol->ymax = fractol->height - 1;
	}
	fractol->go[0] = 1;
}

void	ft_keyhook(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
	{
		if (fractol->fractal[1])
			fractol->max_iteration++;
		else
			fractol->max_iteration *= 1.25;
	}
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
	{
		if (fractol->fractal[1] && fractol->max_iteration > 0)
			fractol->max_iteration--;
		else
			fractol->max_iteration *= 0.75;
	}
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
		fractol->fractal[0] = !fractol->fractal[0];
	fractol->go[0] = 1;
}

void	ft_keyhook_start(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *) param;
	if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		fractol->y_offset = -0.05;
	if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		fractol->y_offset = 0.05;
	if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		fractol->x_offset = -0.05;
	if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		fractol->x_offset = 0.05;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		fractol->mouse_c = !fractol->mouse_c;
	if (keydata.key == MLX_KEY_E && keydata.action != MLX_RELEASE)
		fractol->color += 5;
	if (keydata.key == MLX_KEY_R && keydata.action != MLX_RELEASE)
		fractol->color -= 5;
	if (keydata.key == MLX_KEY_Z && keydata.action != MLX_RELEASE)
		fractol->zoom = 1.25;
	if (keydata.key == MLX_KEY_X && keydata.action != MLX_RELEASE)
		fractol->zoom = 0.75;
	ft_keyhook(keydata, fractol);
}
