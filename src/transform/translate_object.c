/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_object.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:46:44 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:31:25 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "keycodes.h"

int	translate_object(int keycode, t_frame *frame_data)
{
	double	translate_scale;

	translate_scale = 10;
	if (keycode == KEY_W)
	{
		frame_data->translation.y -= translate_scale;
	}
	else if (keycode == KEY_S)
	{
		frame_data->translation.y += translate_scale;
	}
	else if (keycode == KEY_A)
	{
		frame_data->translation.x -= translate_scale;
	}
	else if (keycode == KEY_D)
	{
		frame_data->translation.x += translate_scale;
	}
	return (1);
}
