/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale_object.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:56:27 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:34:17 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "keycodes.h"

int	scale_object(int keycode, t_frame *frame_data)
{
	int	scale_amount;

	scale_amount = 5;
	if (keycode == SCROLL_UP)
	{
		frame_data->scale += scale_amount;
	}
	else if (keycode == SCROLL_DOWN)
	{
		if (frame_data->scale - scale_amount < 2)
		{
			frame_data->scale = 2;
			return (1);
		}
		frame_data->scale -= scale_amount;
	}
	return (1);
}
