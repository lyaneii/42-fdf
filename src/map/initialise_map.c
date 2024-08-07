/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_map.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:41:57 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/19 11:44:35 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

t_map	*initialise_map(int width, int height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->start = NULL;
	return (map);
}
