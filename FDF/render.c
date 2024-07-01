/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:39:04 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/19 21:23:49 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric_view(t_point *p, float ang)
{
	p->x = (p->x - p->y) * cos(ang);
	p->y = (p->x + p->y) * sin(ang) - p->z;
}

void	set_zoom(t_mlx *win, t_point *p1, t_point *p2)
{
	p1->x *= win->zoom;
	p1->y *= win->zoom;
	p1->z *= win->zoom;
	p1->z *= win->z_zoom;
	p2->x *= win->zoom;
	p2->y *= win->zoom;
	p2->z *= win->zoom;
	p2->z *= win->z_zoom;
}

void	ft_bresenhams_alg(t_mlx *win, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		max;

	set_zoom(win, &p1, &p2);
	if (win->view != 3)
	{
		isometric_view(&p1, win->view);
		isometric_view(&p2, win->view);
	}
	p1.x += win->shift_x;
	p1.y += win->shift_y;
	p2.x += win->shift_x;
	p2.y += win->shift_y;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_pixel_put(&win->img, p1.x, p1.y, p1.color * win->c_factor);
		p1.x += x_step;
		p1.y += y_step;
	}
}

int	draw(t_mlx *win)
{
	int	y;
	int	x;

	render_background(&win->img, 0x000000);
	y = 0;
	while (y < win->map->height)
	{
		x = 0;
		while (x < win->map->width)
		{
			if (x < win->map->width - 1)
				ft_bresenhams_alg(win, win->map->coord[y][x],
					win->map->coord[y][x + 1]);
			if (y < win->map->height - 1)
				ft_bresenhams_alg(win, win->map->coord[y][x],
					win->map->coord[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	ft_put_on_screen(win);
	return (0);
}

void	render(t_map *map)
{
	t_mlx	*win;

	win = malloc(sizeof(t_mlx));
	set_up_win(win);
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Fdf");
	win->map = map;
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, arrow_keys, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);
	mlx_hook(win->mlx_win, 17, 0, ft_close, win);
	mlx_loop(win->mlx_connect);
}
