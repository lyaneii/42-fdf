/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_row.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:32:06 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/19 10:59:39 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "row_operations.h"
#include <stdlib.h>

t_input	*new_row(char *input_row)
{
	t_input	*row;

	row = malloc(sizeof(t_input));
	if (row == NULL)
		return (NULL);
	row->row = input_row;
	row->next = NULL;
	return (row);
}
