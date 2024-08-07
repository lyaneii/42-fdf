/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_projected_coordinate.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 16:04:00 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/05 16:13:11 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"
#include "coord_operations.h"
#include <stdlib.h>

t_coord	*new_projected_coordinate(t_vec3 vec, int row, int col, int color)
{
	t_coord	*projected;

	projected = malloc(sizeof(t_coord));
	if (projected == NULL)
		return (NULL);
	projected->loc = vec;
	projected->row = row;
	projected->column = col;
	projected->color = color;
	projected->next = NULL;
	return (projected);
}
