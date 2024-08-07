/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:32:44 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/07 13:36:59 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "frame_data.h"

typedef enum e_direction
{
	NORTHEAST,
	SOUTHEAST,
	SOUTHWEST,
	NORTHWEST,
	OCTANT_NNE,
	OCTANT_ENE,
	OCTANT_ESE,
	OCTANT_SSE,
	OCTANT_SSW,
	OCTANT_WSW,
	OCTANT_WNW,
	OCTANT_NNW
}	t_direction;

t_direction	determine_direction(t_coord a, t_coord b);

void		draw_east(t_frame *frame_data, t_coord start, t_coord dest);
void		draw_north(t_frame *frame_data, t_coord start, t_coord dest);
void		draw_line(t_frame *frame_data, t_coord *a, t_coord *b);
void		connect_points(t_frame *frame_data, t_coord *coords);
void		draw_bounds(t_frame *frame_data);

void		draw_map(t_frame *frame_data);
void		display_transform_info(t_frame *frame_data);

double		ft_abs_double(double nbr);
double		get_slope(double nb1, double nb2);
int			get_diff(int nb1, int nb2);
int			is_in_frame(double x, double y, t_map *map, int *bounds);
void		put_pixel_to_img(t_data *data, int x, int y, int color);
t_coord		*new_projected_coordinate(t_vec3 vec, int row, int col, int color);
t_vec3		get_rgb_diff(int color1, int color2);
t_vec3		get_rgb_slope(t_vec3 color_diff, int increment_diff);
int			rgb_add(int color, t_vec3 rgb_slope);
char		*fdf_itoa(int nbr);
char		*fdf_dtoa(double nbr, unsigned int precision);

t_vec3		apply_transforms(t_frame *frame_data, t_vec3 coordinate);
int			rotate_object(int keycode, t_frame *frame_data);
int			scale_object(int keycode, t_frame *frame_data);
int			translate_object(int keycode, t_frame *frame_data);
int			change_perspective(int keycode, t_frame *frame_data);
int			reset_transforms(t_frame *frame_data);

#endif