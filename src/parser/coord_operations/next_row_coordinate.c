/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_row_coordinate.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/21 11:01:26 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/26 16:41:13 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include <stddef.h>

t_coord	*next_row_coordinate(t_coord *coord)
{
	if (coord->next == NULL)
		return (NULL);
	if (coord->next->column != coord->column)
		return (NULL);
	return (coord->next);
}
