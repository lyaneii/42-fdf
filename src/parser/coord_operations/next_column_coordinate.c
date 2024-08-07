/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_column_coordinate.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/21 10:54:25 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/26 16:40:28 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include <stddef.h>

t_coord	*next_column_coordinate(t_coord *coord)
{
	int	current_column;

	if (coord->next == NULL)
		return (NULL);
	current_column = coord->row;
	coord = coord->next;
	while (coord != NULL && coord->row != current_column)
	{
		coord = coord->next;
	}
	return (coord);
}
