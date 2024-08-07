/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_coordinates.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 19:41:02 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/21 11:30:08 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

void	clear_coordinates(t_coord *start)
{
	t_coord	*tmp;

	while (start != NULL)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}
