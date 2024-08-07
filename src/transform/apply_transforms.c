/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_transforms.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:53:24 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 16:04:39 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"

static t_vec3	apply_rotations(t_vec3 rotation, t_vec3 coordinate)
{
	t_mtx3	rotation_x;
	t_mtx3	rotation_y;
	t_mtx3	rotation_z;

	rotation_x = rotate_x_matrix(rotation.x);
	rotation_y = rotate_y_matrix(rotation.y);
	rotation_z = rotate_z_matrix(rotation.z);
	coordinate = dot_product(rotation_x, coordinate);
	coordinate = dot_product(rotation_y, coordinate);
	coordinate = dot_product(rotation_z, coordinate);
	return (coordinate);
}

static t_vec3	apply_translation(t_vec3 translation, t_vec3 coordinate)
{
	coordinate.x += translation.x;
	coordinate.y += translation.y;
	coordinate.z += translation.z;
	return (coordinate);
}

static t_vec3	apply_scale(int scale, t_vec3 coordinate)
{
	coordinate.x *= scale;
	coordinate.y *= scale;
	coordinate.z *= scale;
	return (coordinate);
}

static t_vec3	apply_perspective(int perspective, t_vec3 coordinate)
{
	t_mtx3	perspective_matrix;

	if (perspective == 1)
		perspective_matrix = isometric_matrix();
	else if (perspective == 2)
		perspective_matrix = perspective_projection_matrix(coordinate.z, 10);
	else
		perspective_matrix = orthogonal_matrix();
	coordinate = dot_product(perspective_matrix, coordinate);
	return (coordinate);
}

t_vec3	apply_transforms(t_frame *frame_data, t_vec3 coordinate)
{
	coordinate = apply_rotations(frame_data->rotation, coordinate);
	coordinate = apply_perspective(frame_data->perspective, coordinate);
	coordinate = apply_scale(frame_data->scale, coordinate);
	coordinate = apply_translation(frame_data->translation, coordinate);
	return (coordinate);
}
