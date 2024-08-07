/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:36:06 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 13:07:24 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "row_operations.h"
#include "coord_operations.h"
#include "get_next_line.h"
#include "libft.h"

static int	parse_coord(t_coord **head, int x, int z, char *row_coord)
{
	t_coord	*coord;
	int		color;

	if (row_coord[0] == '\n')
		return (0);
	color = get_coordinate_color(row_coord);
	coord = new_coordinate(x, ft_atoi(row_coord), z, color);
	if (coord == NULL)
		return (-1);
	append_coordinate(head, coord);
	return (0);
}

static t_coord	*row_to_coords(char *row, int z_coord)
{
	t_coord	*head;
	char	**row_coords;
	int		i;
	int		success;

	row_coords = ft_split(row, ' ');
	if (row_coords == NULL)
		return (NULL);
	i = 0;
	head = NULL;
	success = 0;
	while (row_coords[i] != 0)
	{
		if (success == 0)
			success = parse_coord(&head, i, z_coord, row_coords[i]);
		free(row_coords[i]);
		i++;
	}
	free(row_coords);
	if (success == -1)
		return (clear_coordinates(head), NULL);
	return (head);
}

static t_coord	*rows_to_coordinates(t_input *input)
{
	t_coord	*head;
	t_coord	*row_coords;
	int		z_coord;

	head = NULL;
	z_coord = 0;
	while (input != NULL)
	{
		row_coords = row_to_coords(input->row, z_coord);
		if (row_coords == NULL)
			return (clear_coordinates(head), NULL);
		append_coordinate(&head, row_coords);
		z_coord++;
		input = input->next;
	}
	return (head);
}

static t_input	*input_to_rows(int fd)
{
	t_input	*head;
	t_input	*row;
	char	*input_row;

	head = NULL;
	input_row = get_next_line(fd);
	if (input_row == NULL)
		return (NULL);
	while (input_row != NULL)
	{
		row = new_row(input_row);
		if (row == NULL)
			return (clear_rows(&head), free(input_row), NULL);
		append_row(&head, row);
		input_row = get_next_line(fd);
	}
	return (head);
}

t_coord	*parse_input(int fd)
{
	t_input	*rows;
	t_coord	*start;

	rows = input_to_rows(fd);
	if (rows == NULL)
		return (NULL);
	start = rows_to_coordinates(rows);
	clear_rows(&rows);
	if (start == NULL)
		return (NULL);
	return (start);
}
