/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_east.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:47:58 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 18:22:02 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "draw.h"

void	draw_east(t_frame *frame_data, t_coord start, t_coord dest)
{
	int		diff_x;
	int		diff_y;
	double	slope;
	t_vec3	rgb_diff;
	t_vec3	rgb_slope;

	diff_x = get_diff(start.loc.x, dest.loc.x);
	diff_y = get_diff(start.loc.y, dest.loc.y);
	slope = get_slope(diff_x, diff_y);
	rgb_diff = get_rgb_diff(start.color, dest.color);
	rgb_slope = get_rgb_slope(rgb_diff, diff_x);
	while (start.loc.x <= dest.loc.x)
	{
		if (is_in_frame(start.loc.x, start.loc.y, \
			frame_data->map, frame_data->bounds))
		{
			put_pixel_to_img(frame_data->img, \
				start.loc.x, start.loc.y, start.color);
		}
		start.color = rgb_add(start.color, rgb_slope);
		start.loc.x += 1;
		start.loc.y += slope;
	}
}
