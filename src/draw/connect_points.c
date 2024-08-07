/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   connect_points.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:56:58 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 20:22:36 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "draw.h"

static void	connect_rows(t_frame *frame_data, t_coord *coords)
{
	while (coords)
	{
		draw_line(frame_data, coords, next_row_coordinate(coords));
		coords = coords->next;
	}
}

static void	connect_columns(t_frame *frame_data, t_coord *coords)
{
	while (coords)
	{
		draw_line(frame_data, coords, next_column_coordinate(coords));
		coords = coords->next;
	}
}

void	connect_points(t_frame *frame_data, t_coord *coords)
{
	connect_columns(frame_data, coords);
	connect_rows(frame_data, coords);
}
