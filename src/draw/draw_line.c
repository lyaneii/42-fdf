/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:43:48 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 20:22:36 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "frame_data.h"
#include "draw.h"

void	draw_line(t_frame *frame_data, t_coord *a, t_coord *b)
{
	t_direction	direction;

	if (a == NULL || b == NULL)
		return ;
	direction = determine_direction(*a, *b);
	if (direction == OCTANT_SSW)
		draw_north(frame_data, *b, *a);
	else if (direction == OCTANT_WSW)
		draw_east(frame_data, *b, *a);
	else if (direction == OCTANT_NNW)
		draw_north(frame_data, *a, *b);
	else if (direction == OCTANT_WNW)
		draw_east(frame_data, *b, *a);
	else if (direction == OCTANT_SSE)
		draw_north(frame_data, *b, *a);
	else if (direction == OCTANT_ESE)
		draw_east(frame_data, *a, *b);
	else if (direction == OCTANT_NNE)
		draw_north(frame_data, *a, *b);
	else if (direction == OCTANT_ENE)
		draw_east(frame_data, *a, *b);
}
