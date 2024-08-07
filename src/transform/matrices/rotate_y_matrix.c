/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_y_matrix.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:31:19 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:31:59 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mtx3	rotate_y_matrix(double angle)
{
	t_mtx3	matrix;

	matrix.a = new_vector(cos(angle), 0, sin(angle));
	matrix.b = new_vector(0, 1, 0);
	matrix.c = new_vector(-sin(angle), 0, cos(angle));
	return (matrix);
}
