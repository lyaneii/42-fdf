/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:54:45 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/05 16:18:06 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stddef.h>

t_map	*create_map(t_coord *start, int width, int height)
{
	t_map	*map;

	map = initialise_map(width, height);
	if (map == NULL)
		return (NULL);
	map->start = start;
	normalise_coords(&map->start);
	return (map);
}
