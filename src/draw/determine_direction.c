/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   determine_direction.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:33:37 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 16:20:24 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include "draw.h"

static t_direction	determine_octant(t_direction ordinal, int diffx, int diffy)
{
	int	use_y_increment;

	use_y_increment = 0;
	if (ft_abs_double(get_slope(diffx, diffy)) > 1)
		use_y_increment = 1;
	if (ordinal == SOUTHWEST && use_y_increment == 1)
		return (OCTANT_SSW);
	if (ordinal == SOUTHWEST && use_y_increment == 0)
		return (OCTANT_WSW);
	if (ordinal == NORTHWEST && use_y_increment == 1)
		return (OCTANT_NNW);
	if (ordinal == NORTHWEST && use_y_increment == 0)
		return (OCTANT_WNW);
	if (ordinal == SOUTHEAST && use_y_increment == 1)
		return (OCTANT_SSE);
	if (ordinal == SOUTHEAST && use_y_increment == 0)
		return (OCTANT_ESE);
	if (ordinal == NORTHEAST && use_y_increment == 1)
		return (OCTANT_NNE);
	if (ordinal == NORTHEAST && use_y_increment == 0)
		return (OCTANT_ENE);
	return (0);
}

t_direction	determine_direction(t_coord a, t_coord b)
{
	int	diff_x;
	int	diff_y;
	int	negative_x;
	int	negative_y;

	diff_x = get_diff(a.loc.x, b.loc.x);
	diff_y = get_diff(a.loc.y, b.loc.y);
	negative_x = 0;
	negative_y = 0;
	if (diff_x < 0)
		negative_x = 1;
	if (diff_y < 0)
		negative_y = 1;
	if (negative_x == 1 && negative_y == 1)
		return (determine_octant(SOUTHWEST, diff_x, diff_y));
	else if (negative_x == 1 && negative_y == 0)
		return (determine_octant(NORTHWEST, diff_x, diff_y));
	else if (negative_x == 0 && negative_y == 1)
		return (determine_octant(SOUTHEAST, diff_x, diff_y));
	else
		return (determine_octant(NORTHEAST, diff_x, diff_y));
}
