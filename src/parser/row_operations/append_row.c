/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append_row.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:32:59 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/19 10:41:55 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "row_operations.h"
#include <stddef.h>

void	append_row(t_input **head, t_input *row)
{
	if (*head == NULL)
		*head = row;
	else
		last_row(*head)->next = row;
}
