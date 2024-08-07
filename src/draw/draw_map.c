/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:51:21 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:52:30 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "draw.h"
#include "libft.h"
#include <mlx.h>
#include <stddef.h>

void	draw_map(t_frame *frame_data)
{
	t_coord	*start;
	t_vec3	projected;
	t_coord	*new_coordinate;
	t_coord	*projected_points;

	projected_points = NULL;
	start = frame_data->map->start;
	ft_bzero(frame_data->img->addr, frame_data->map->width * \
		frame_data->map->height * (frame_data->img->bits_per_pixel / 8));
	while (start)
	{
		projected = apply_transforms(frame_data, start->loc);
		new_coordinate = new_projected_coordinate(projected, \
							start->row, start->column, start->color);
		if (new_coordinate == NULL)
			return (clear_coordinates(projected_points));
		append_coordinate(&projected_points, new_coordinate);
		start = start->next;
	}
	draw_bounds(frame_data);
	connect_points(frame_data, projected_points);
	mlx_put_image_to_window(frame_data->mlx, \
		frame_data->mlx_win, frame_data->img->img, 0, 0);
	display_transform_info(frame_data);
	clear_coordinates(projected_points);
}
