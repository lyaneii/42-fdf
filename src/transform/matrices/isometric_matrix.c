/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isometric_matrix.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:22:25 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:29:26 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mtx3	isometric_matrix(void)
{
	t_mtx3	matrix;

	matrix.a = new_vector(sqrt(2) / 2, -sqrt(2) / 2, 0);
	matrix.b = new_vector(sqrt(6) / 6, sqrt(6) / 6, -sqrt(6) / 3);
	matrix.c = new_vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);
	return (matrix);
}
