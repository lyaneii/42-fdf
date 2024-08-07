/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coord_operations.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 11:35:42 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/05 16:19:22 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_OPERATIONS_H
# define COORD_OPERATIONS_H
# include "transform.h"

typedef struct s_coord
{
	t_vec3			loc;
	int				row;
	int				column;
	int				color;
	struct s_coord	*next;
}	t_coord;

t_coord	*new_coordinate(int x, int y, int z, int color);
t_coord	*last_coordinate(t_coord *head);
int		get_coordinate_color(char *coord);
void	append_coordinate(t_coord **head, t_coord *coord);
t_coord	*next_column_coordinate(t_coord *coord);
t_coord	*next_row_coordinate(t_coord *coord);
void	clear_coordinates(t_coord *start);
void	normalise_coords(t_coord **head);

#endif