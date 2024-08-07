/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:32:56 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/18 16:47:39 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "row_operations.h"
#include <stddef.h>

t_input	*last_row(t_input *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}
