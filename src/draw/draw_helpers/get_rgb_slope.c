/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_rgb_slope.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 16:34:48 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 16:36:31 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vec3	get_rgb_slope(t_vec3 color_diff, int increment_diff)
{
	t_vec3	rgb_slope;

	rgb_slope.x = color_diff.x / increment_diff;
	rgb_slope.y = color_diff.y / increment_diff;
	rgb_slope.z = color_diff.z / increment_diff;
	return (rgb_slope);
}
