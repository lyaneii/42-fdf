/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_transforms.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 18:00:46 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:31:31 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"

int	reset_transforms(t_frame *frame_data)
{
	double	default_x;
	double	default_y;

	default_x = frame_data->map->width / 2;
	default_y = frame_data->map->height / 2;
	frame_data->translation = new_vector(default_x, default_y, 0);
	frame_data->rotation.x = degrees_to_radians(90);
	frame_data->rotation.y = degrees_to_radians(0);
	frame_data->rotation.z = degrees_to_radians(90);
	frame_data->scale = 10;
	return (1);
}
