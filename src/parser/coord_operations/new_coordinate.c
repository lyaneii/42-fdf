/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_coordinate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:05:13 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/26 15:57:01 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include <stdlib.h>

t_coord	*new_coordinate(int x, int y, int z, int color)
{
	t_coord	*coordinate;

	coordinate = malloc(sizeof(t_coord));
	if (coordinate == NULL)
		return (NULL);
	coordinate->loc.x = x;
	coordinate->loc.y = y;
	coordinate->loc.z = z;
	coordinate->row = 0;
	coordinate->column = 0;
	coordinate->color = color;
	coordinate->next = NULL;
	return (coordinate);
}
