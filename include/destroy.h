/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 11:52:28 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/07 14:00:48 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H
# include "frame_data.h"

void	destroy_mlx(void *mlx, void *mlx_win, t_data *img);
void	destroy_map(t_map *map);
void	destroy_all(t_frame *frame_data);
int		end_loop(t_frame *frame_data);
void	print_error(int code);

#endif