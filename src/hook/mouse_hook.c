/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_hook.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:54:55 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 15:35:31 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "draw.h"
#include "keycodes.h"

static int	is_scroll_key(int keycode)
{
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
		return (1);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_frame *frame_data)
{
	(void)x;
	(void)y;
	if (is_scroll_key(keycode))
	{
		scale_object(keycode, frame_data);
		draw_map(frame_data);
	}
	return (0);
}
