/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_itoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwokpo <kwokpo@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 16:08:35 by kwokpo        #+#    #+#                 */
/*   Updated: 2024/03/06 17:29:23 by kwokpo        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_nbr_size(int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static void	nbr_to_string(char *string, int nbr, int i)
{
	int	remainder;
	int	digit;

	digit = nbr % 10;
	remainder = nbr / 10;
	if (nbr < 0)
	{
		string[0] = '-';
		digit = -digit;
		remainder = -remainder;
	}
	if (remainder > 0)
		nbr_to_string(string, remainder, i - 1);
	string[i] = digit + '0';
}

char	*fdf_itoa(int nbr)
{
	char	*str;
	int		size;

	size = get_nbr_size(nbr);
	if (nbr < 0)
		size++;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	nbr_to_string(str, nbr, size - 1);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", fdf_itoa(-1));
// 	return (0);
// }
