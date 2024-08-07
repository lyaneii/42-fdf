/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_multiply.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:28:27 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:30:44 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

double	vector_multiply(t_vec3 vec_a, t_vec3 vec_b)
{
	double	vecproduct;

	vecproduct = vec_a.x * vec_b.x + vec_a.y * vec_b.y + vec_a.z * vec_b.z;
	return (vecproduct);
}
