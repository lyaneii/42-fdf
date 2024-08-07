/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_from_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 12:14:23 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 13:08:51 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "map.h"
#include "parser.h"

t_map	*map_from_file(char *file)
{
	t_map	*map;
	t_coord	*input;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	input = parse_input(fd);
	if (input == NULL)
		return (NULL);
	map = create_map(input, 1920, 1080);
	if (map == NULL)
		return (clear_coordinates(input), NULL);
	return (map);
}
