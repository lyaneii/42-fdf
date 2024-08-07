/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_bounds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 15:40:07 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:37:25 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "draw.h"

static void	draw_edge_vertical(void *img, int *x, int *y)
{
	int	inc;

	inc = y[0];
	while (inc != y[1])
	{
		put_pixel_to_img(img, x[0], inc, 0xFFFFFF);
		put_pixel_to_img(img, x[1], inc, 0xFFFFFF);
		inc++;
	}
}

static void	draw_edge_horizontal(void *img, int *x, int *y)
{
	int	inc;

	inc = x[0];
	while (inc != x[1])
	{
		put_pixel_to_img(img, inc, y[0], 0xFFFFFF);
		put_pixel_to_img(img, inc, y[1], 0xFFFFFF);
		inc++;
	}
}

void	draw_bounds(t_frame *frame_data)
{
	int	x[2];
	int	y[2];

	x[0] = frame_data->bounds[0] / 2;
	x[1] = frame_data->map->width - frame_data->bounds[0] / 2;
	y[0] = frame_data->bounds[1] / 2;
	y[1] = frame_data->map->height - frame_data->bounds[1] / 2;
	draw_edge_horizontal(frame_data->img, x, y);
	draw_edge_vertical(frame_data->img, x, y);
}
