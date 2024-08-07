/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 19:41:53 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 12:15:36 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "coord_operations.h"

typedef struct s_map
{
	int		width;
	int		height;
	t_coord	*start;
}	t_map;

t_map	*initialise_map(int width, int height);
t_map	*create_map(t_coord *start, int width, int height);
t_map	*map_from_file(char *file);

#endif