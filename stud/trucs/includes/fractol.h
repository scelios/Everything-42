/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:53:54 by beaudibe          #+#    #+#             */
/*   Updated: 2023/01/26 14:30:57 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t		width;
	int32_t		height;
	double		mousex;
	double		mousey;
	double		zoom;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		x_offset;
	double		y_offset;
	int			mouse_c;
	int			max_iteration;
	int			color;
	int			go[3];
	int			fractal[3];
	int			julia;
	int			hour;
}	t_fractol;
void	shutdown();

int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);
int		ft_get_iteration(t_fractol *fractol, double zx, \
		double zy, double temp[2]);
int		ft_get_iteration(t_fractol *fractol, double zx, \
		double zy, double temp[2]);

void	ft_scrollhook(double xdelta, double ydelta, void *param);
void	ft_close_hook(void *param);
void	ft_keyhook(mlx_key_data_t keydata, t_fractol *fractol);
void	ft_keyhook_start(mlx_key_data_t keydata, void *param);
void	ft_zoom_move(t_fractol	*fractol);
void	ft_resize(int32_t width, int32_t height, void *param);
void	ft_cursor(double xpos, double ypos, void *param);
void	ft_julia(t_fractol *fractol, double temp[2]);
void	ft_hook(void *param);
void	ft_draw_rectangle(t_fractol *fractol, double x[2], \
		double y[2], int color);
void	ft_mandelbrot_julia(t_fractol *fractol, int x, int y, double zx);
void	ft_cube(t_fractol *fractol, double x[2], double y[2], int depth);
void	ft_calcul_cube_rectangle(t_fractol *fractol, double x[2], \
		double y[2], double new_size[3]);
void	ft_calcul_cube(t_fractol *fractol, double x[2], \
		double y[2], double new_size[5]);
void	ft_mouse_hook(mouse_key_t button, action_t action, \
		modifier_key_t mods, void *param);

#endif
