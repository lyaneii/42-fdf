/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dot_product.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:29:54 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 19:42:01 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vec3	dot_product(t_mtx3 matrix, t_vec3 vec)
{
	t_vec3	dotproduct;

	dotproduct.x = vector_multiply(matrix.a, vec);
	dotproduct.y = vector_multiply(matrix.b, vec);
	dotproduct.z = vector_multiply(matrix.c, vec);
	return (dotproduct);
}
