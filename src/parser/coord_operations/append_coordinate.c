/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append_coordinate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 11:44:19 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/21 11:30:08 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include <stddef.h>

void	append_coordinate(t_coord **head, t_coord *coord)
{
	if (*head == NULL)
		*head = coord;
	else
		last_coordinate(*head)->next = coord;
}
