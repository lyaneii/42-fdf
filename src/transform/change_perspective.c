/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_perspective.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:52:56 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:31:33 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"

int	change_perspective(int keycode, t_frame *frame_data)
{
	frame_data->perspective = keycode - '0';
	return (1);
}
