/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 16:37:41 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 17:06:15 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

int	rgb_add(int color, t_vec3 rgb_slope)
{
	color += (int)rgb_slope.z;
	color += (int)rgb_slope.y << 8;
	color += (int)rgb_slope.x << 16;
	return (color);
}

// #include "draw.h"
// #include <stdio.h>
// int	main(void)
// {
// 	int	color = 0x000000;
// 	int	color2 = 0x0A0A0A;
// 	t_vec3	rgb_diff;
// 	t_vec3	rgb_slope;

// 	rgb_diff = get_rgb_diff(color, color2);
// 	rgb_slope = get_rgb_slope(rgb_diff, 10);
// 	printf("%f %f %f\n", rgb_slope.x, rgb_slope.y, rgb_slope.z);
// 	printf("%.6X\n", color);
// 	while (color < color2)
// 	{
// 		color = rgb_add(color, rgb_slope);
// 		printf("%.6X\n", color);
// 	}
// 	return (0);
// }
