/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_z_matrix.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:31:36 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:31:54 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mtx3	rotate_z_matrix(double angle)
{
	t_mtx3	matrix;

	matrix.a = new_vector(cos(angle), -sin(angle), 0);
	matrix.b = new_vector(sin(angle), cos(angle), 0);
	matrix.c = new_vector(0, 0, 1);
	return (matrix);
}
