/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perspective_matrix.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:29:07 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:29:17 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_mtx3	perspective_projection_matrix(double z, double distance)
{
	t_mtx3	matrix;

	matrix.a = new_vector(1 / (distance - z), 0, 0);
	matrix.b = new_vector(0, 1 / (distance - z), 0);
	matrix.c = new_vector(0, 0, 0);
	return (matrix);
}
