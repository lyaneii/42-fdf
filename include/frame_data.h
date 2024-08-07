/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_data.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:41:27 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 15:42:20 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_DATA_H
# define FRAME_DATA_H
# include "map.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_frame
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_data	*img;
	t_vec3	rotation;
	t_vec3	translation;
	int		bounds[2];
	int		perspective;
	int		scale;
}	t_frame;

#endif