/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   degrees_to_radians.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 18:01:00 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/04 18:01:11 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	degrees_to_radians(int degrees)
{
	return (degrees * M_PI / 180);
}
