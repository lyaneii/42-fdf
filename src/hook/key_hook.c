/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:47:19 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 14:03:16 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "frame_data.h"
#include "draw.h"
#include "keycodes.h"
#include "destroy.h"

static int	is_perspective_key(int keycode)
{
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
		return (1);
	return (0);
}

static int	is_translate_key(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A || \
		keycode == KEY_S || keycode == KEY_D)
		return (1);
	return (0);
}

static int	is_rotate_key(int keycode)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
		keycode == KEY_UP || keycode == KEY_DOWN)
		return (1);
	return (0);
}

int	key_hook(int keycode, t_frame *frame_data)
{
	int	redraw;

	redraw = 0;
	if (keycode == KEY_ESC)
		end_loop(frame_data);
	else if (is_rotate_key(keycode))
		redraw = rotate_object(keycode, frame_data);
	else if (is_translate_key(keycode))
		redraw = translate_object(keycode, frame_data);
	else if (is_perspective_key(keycode))
		redraw = change_perspective(keycode, frame_data);
	else if (keycode == KEY_R)
		redraw = reset_transforms(frame_data);
	if (redraw == 1)
		draw_map(frame_data);
	return (0);
}
