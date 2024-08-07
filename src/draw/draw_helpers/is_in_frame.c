/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_in_frame.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:49:16 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:10:26 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"

int	is_in_frame(double x, double y, t_map *map, int *bounds)
{
	int	x_bounds[2];
	int	y_bounds[2];

	x_bounds[0] = bounds[0] / 2;
	x_bounds[1] = map->width - bounds[0] / 2;
	y_bounds[0] = bounds[1] / 2;
	y_bounds[1] = map->height - bounds[1] / 2;
	if (x < x_bounds[0] || y < y_bounds[0])
		return (0);
	if (x > x_bounds[1] || y > y_bounds[1])
		return (0);
	return (1);
}
