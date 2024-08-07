/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalise_coords.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 16:17:07 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 16:18:28 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord_operations.h"

static int	get_max_width(t_coord *head)
{
	int	max_width;

	max_width = 0;
	while (head)
	{
		if (head->loc.x > max_width)
			max_width = head->loc.x;
		head = head->next;
	}
	return (max_width + 1);
}

static int	get_max_length(t_coord *head)
{
	int	max_depth;

	max_depth = 0;
	while (head)
	{
		if (head->loc.z > max_depth)
			max_depth = head->loc.z;
		head = head->next;
	}
	return (max_depth + 1);
}

static void	normalise_x(t_coord *head)
{
	int	start;
	int	max_width;

	max_width = get_max_width(head);
	start = 0 - (max_width / 2);
	while (head)
	{
		head->row = head->loc.x;
		head->loc.x = start;
		start++;
		if (head->next && head->next->loc.z != head->loc.z)
			start = 0 - (max_width / 2);
		head = head->next;
	}
}

static void	normalise_z(t_coord *head)
{
	int	start;
	int	max_depth;
	int	should_inc;

	max_depth = get_max_length(head);
	start = 0 - (max_depth / 2);
	should_inc = 0;
	while (head)
	{
		head->column = head->loc.z;
		should_inc = 0;
		if (head->next && head->next->loc.z != head->loc.z)
			should_inc = 1;
		head->loc.z = start;
		if (should_inc == 1)
			start++;
		head = head->next;
	}
}

void	normalise_coords(t_coord **head)
{
	normalise_x(*head);
	normalise_z(*head);
}
