/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_coordinate_color.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:41:06 by kwchu         #+#    #+#                 */
/*   Updated: 2024/03/06 17:52:40 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid_hex_start(char *string)
{
	if (string[0] == '0' && string[1] == 'x')
		return (1);
	return (0);
}

static int	char_to_nbr_base(char c, const char *base)
{
	int		i;

	i = 0;
	c = ft_toupper(c);
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	hex_to_color(char *string)
{
	int	i;
	int	color;
	int	rgb_mask;

	if (valid_hex_start(string) == 0)
		return (0);
	i = 2;
	color = 0;
	rgb_mask = 20;
	while (string[i] != 0)
	{
		color += (char_to_nbr_base(string[i], "0123456789ABCDEF") << rgb_mask);
		rgb_mask -= 4;
		i++;
	}
	return (color);
}

int	get_coordinate_color(char *coord)
{
	int	i;

	i = 0;
	while (coord[i] != 0)
	{
		if (coord[i] == ',')
			return (hex_to_color(coord + i + 1));
		i++;
	}
	return (0xFFFFFF);
}
