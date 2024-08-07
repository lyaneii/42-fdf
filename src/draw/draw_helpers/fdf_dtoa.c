/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_dtoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 16:32:59 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:45:12 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"
#include <stdlib.h>

static int	my_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static double	get_float_part(double nbr)
{
	return (nbr - (int)nbr);
}

static int	float_res_to_int(double nbr, unsigned int precision)
{
	while (precision > 0)
	{
		nbr = nbr * 10;
		precision--;
	}
	return ((int)nbr);
}

static char	*add_dot(char *num, unsigned int precision)
{
	char	*dot;

	if (precision > 0)
	{
		dot = ft_strjoin(num, ".");
		free(num);
		if (dot == NULL)
			return (NULL);
	}
	else
		return (num);
	return (dot);
}

char	*fdf_dtoa(double nbr, unsigned int precision)
{
	char	*str;
	char	*dot;
	char	*str_num;
	char	*str_res;
	int		res;

	res = my_abs(float_res_to_int(get_float_part(nbr), precision));
	str_num = fdf_itoa((int)nbr);
	if (str_num == NULL)
		return (NULL);
	dot = add_dot(str_num, precision);
	if (dot == NULL)
		return (NULL);
	str_res = fdf_itoa(res);
	if (str_res == NULL)
		return (free(dot), NULL);
	str = ft_strjoin(dot, str_res);
	free(dot);
	free(str_res);
	if (str == NULL)
		return (NULL);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = fdf_dtoa(12123153.23251354, 6);

// 	printf("%s\n", str);
// 	free(str);
// 	return (0);	
// }
