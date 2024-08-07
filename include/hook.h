/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 19:54:27 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 20:22:36 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include "frame_data.h"

int	key_hook(int keycode, t_frame *frame_data);
int	mouse_hook(int keycode, int x, int y, t_frame *frame_data);

#endif