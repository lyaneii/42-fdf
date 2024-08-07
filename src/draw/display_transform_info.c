/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_transform_info.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 15:36:40 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:56:15 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "draw.h"

static void	display_double(t_frame *frame_data, int x, int y, double nbr)
{
	char	*str_double;

	str_double = fdf_dtoa(nbr, 3);
	if (str_double == NULL)
		return ;
	mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
		x, y, 0xFFFFFF, str_double);
	free(str_double);
}

static void	display_int(t_frame *frame_data, int x, int y, int nbr)
{
	char	*str_int;

	str_int = fdf_itoa(nbr);
	if (str_int == NULL)
		return ;
	mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
		x, y, 0xFFFFFF, str_int);
	free(str_int);
}

static void	display_perspective(t_frame *frame_data, int x, int y, int p)
{
	if (p == 1)
	{
		mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
			x, y, 0xFFFFFF, "Isometric View");
	}
	else if (p == 2)
	{
		mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
			x, y, 0xFFFFFF, "Perspective View");
	}
	else
	{
		mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
			x, y, 0xFFFFFF, "Orthogonal View");
	}
}

void	display_transform_info(t_frame *frame_data)
{
	int	start;
	int	offset;

	start = 50;
	offset = 20;
	display_perspective(frame_data, \
		start, start, frame_data->perspective);
	mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
		start, start + 1 * offset, 0xFFFFFF, "Scale");
	display_int(frame_data, start, \
		start + 2 * offset, frame_data->scale);
	mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
		start, start + 3 * offset, 0xFFFFFF, "Rotation");
	display_double(frame_data, start, \
		start + 4 * offset, frame_data->rotation.x);
	display_double(frame_data, start, \
		start + 5 * offset, frame_data->rotation.y);
	display_double(frame_data, start, \
		start + 6 * offset, frame_data->rotation.z);
	mlx_string_put(frame_data->mlx, frame_data->mlx_win, \
		start, start + 7 * offset, 0xFFFFFF, "Location");
	display_int(frame_data, start, \
		start + 8 * offset, frame_data->translation.x);
	display_int(frame_data, start, \
		start + 9 * offset, frame_data->translation.y);
}
