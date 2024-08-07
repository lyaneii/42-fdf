/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_x_matrix.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:31:05 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:32:00 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mtx3	rotate_x_matrix(double angle)
{
	t_mtx3	matrix;

	matrix.a = new_vector(1, 0, 0);
	matrix.b = new_vector(0, cos(angle), -sin(angle));
	matrix.c = new_vector(0, sin(angle), cos(angle));
	return (matrix);
}
