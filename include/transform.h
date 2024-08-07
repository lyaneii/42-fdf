/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/21 10:36:25 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/04 20:50:38 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_mtx3
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
}	t_mtx3;

t_vec3	new_vector(double x, double y, double z);
t_vec3	dot_product(t_mtx3 matrix, t_vec3 vec);
double	vector_multiply(t_vec3 vec_a, t_vec3 vec_b);
double	degrees_to_radians(int degrees);

t_mtx3	rotate_x_matrix(double angle);
t_mtx3	rotate_y_matrix(double angle);
t_mtx3	rotate_z_matrix(double angle);

t_mtx3	isometric_matrix(void);
t_mtx3	orthogonal_matrix(void);
t_mtx3	perspective_projection_matrix(double z, double distance);

#endif