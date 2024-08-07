/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_coordinate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 11:44:00 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/21 11:30:08 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"
#include <stddef.h>

t_coord	*last_coordinate(t_coord *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}
