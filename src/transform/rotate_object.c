/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_object.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:46:23 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:33:08 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "keycodes.h"

int	rotate_object(int keycode, t_frame *frame_data)
{
	double	rotate_scale;

	rotate_scale = degrees_to_radians(5);
	if (keycode == KEY_LEFT)
	{
		frame_data->rotation.z += rotate_scale;
	}
	else if (keycode == KEY_RIGHT)
	{
		frame_data->rotation.z -= rotate_scale;
	}
	else if (keycode == KEY_UP)
	{
		frame_data->rotation.x += rotate_scale;
	}
	else if (keycode == KEY_DOWN)
	{
		frame_data->rotation.x -= rotate_scale;
	}
	return (1);
}
