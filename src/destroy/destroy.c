/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 11:52:57 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 14:02:34 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "frame_data.h"
#include "libft.h"

void	destroy_mlx(void *mlx, void *mlx_win, t_data *img)
{
	if (mlx == NULL)
		return ;
	if (img != NULL && img->img != NULL)
		mlx_destroy_image(mlx, img->img);
	if (mlx_win != NULL)
		mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->start != NULL)
		clear_coordinates(map->start);
	free(map);
}

void	destroy_all(t_frame *frame_data)
{
	destroy_mlx(frame_data->mlx, frame_data->mlx_win, frame_data->img);
	destroy_map(frame_data->map);
}

int	end_loop(t_frame *frame_data)
{
	mlx_loop_end(frame_data->mlx);
	return (0);
}

void	print_error(int code)
{
	if (code == 0)
		ft_putstr_fd("Usage: ./fdf <filename>\n", 1);
	else if (code == 1)
		ft_putstr_fd("Error: could not parse map.\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error: could not initialise mlx.\n", 2);
	else if (code == 3)
		ft_putstr_fd("Error: could not initialise mlx_window.\n", 2);
	else if (code == 4)
		ft_putstr_fd("Error: could not create mlx_image.\n", 2);
	else if (code == 5)
		ft_putstr_fd("Error: could not obtain mlx_image address.\n", 2);
}
