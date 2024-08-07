/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pixel_to_img.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 18:07:19 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/05 16:13:02 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "frame_data.h"

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
