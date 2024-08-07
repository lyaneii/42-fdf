/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color_ramp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 16:25:17 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 16:31:54 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

static int	color_diff(int color1, int color2)
{
	return (color2 - color1);
}

t_vec3	get_rgb_diff(int color1, int color2)
{
	t_vec3	color_ramp;

	color_ramp.x = color_diff((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF);
	color_ramp.y = color_diff((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF);
	color_ramp.z = color_diff(color1 & 0xFF, color2 & 0xFF);
	return (color_ramp);
}
