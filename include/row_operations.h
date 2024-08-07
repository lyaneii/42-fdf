/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   row_operations.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:30:49 by kwchu         #+#    #+#                 */
/*   Updated: 2024/02/19 10:47:56 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROW_OPERATIONS_H
# define ROW_OPERATIONS_H

typedef struct s_input
{
	char			*row;
	struct s_input	*next;
}	t_input;

t_input	*new_row(char *input_row);
t_input	*last_row(t_input *head);
void	append_row(t_input **head, t_input *row);
void	clear_rows(t_input **rows);

#endif