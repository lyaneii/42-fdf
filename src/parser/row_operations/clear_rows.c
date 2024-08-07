/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_rows.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 20:06:54 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/19 11:30:27 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "row_operations.h"
#include <stdlib.h>

void	clear_rows(t_input **rows)
{
	t_input	*tmp;

	if (*rows == NULL)
		return ;
	while (*rows != NULL)
	{
		tmp = *rows;
		*rows = (*rows)->next;
		free(tmp->row);
		free(tmp);
	}
	*rows = NULL;
}
