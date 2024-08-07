/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 11:32:15 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 14:05:29 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "hook.h"
#include "parser.h"
#include "destroy.h"
#include "draw.h"
#include <X11/X.h>

static int	init_frame_data(t_frame *data, t_map *map)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error(2), -1);
	data->mlx_win = mlx_new_window(data->mlx, map->width, map->height, "fdf");
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx);
		return (print_error(3), -1);
	}
	data->img = NULL;
	data->map = map;
	data->perspective = 1;
	data->rotation.x = degrees_to_radians(90);
	data->rotation.y = degrees_to_radians(0);
	data->rotation.z = degrees_to_radians(90);
	data->translation = new_vector(map->width / 2, map->height / 2, 0);
	data->scale = 10;
	data->bounds[0] = 300;
	data->bounds[1] = 200;
	return (0);
}

static void	init_hooks(void *mlx_win, t_frame *frame_data)
{
	mlx_hook(mlx_win, 2, 1L << 0, key_hook, frame_data);
	mlx_hook(mlx_win, DestroyNotify, StructureNotifyMask, end_loop, frame_data);
	mlx_mouse_hook(mlx_win, mouse_hook, frame_data);
}

int	main(int argc, char **argv)
{
	t_frame	frame_data;
	t_map	*map;
	t_data	img;

	if (argc != 2)
		return (print_error(0), 1);
	map = map_from_file(argv[1]);
	if (map == NULL)
		return (print_error(1), 1);
	if (init_frame_data(&frame_data, map) == -1)
		return (destroy_map(map), 1);
	img.img = mlx_new_image(frame_data.mlx, map->width, map->height);
	if (img.img == NULL)
		return (destroy_all(&frame_data), print_error(4), 1);
	img.addr = mlx_get_data_addr(img.img, \
		&img.bits_per_pixel, &img.line_length, &img.endian);
	if (img.addr == NULL)
		return (destroy_all(&frame_data), print_error(5), 1);
	frame_data.img = &img;
	draw_map(&frame_data);
	init_hooks(frame_data.mlx_win, &frame_data);
	mlx_loop(frame_data.mlx);
	destroy_all(&frame_data);
	return (0);
}
