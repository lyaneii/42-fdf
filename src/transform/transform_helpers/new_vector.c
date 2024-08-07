/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_vector.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 17:23:18 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 17:29:32 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_vec3	new_vector(double x, double y, double z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
