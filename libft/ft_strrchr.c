/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kwchu <kwchu@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:24:04 by kwchu         #+#    #+#                 */
/*   Updated: 2023/10/09 15:16:49 by kwchu         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "hallo";
// 	char	c = 'l';

// 	printf("strrchr %s\n", strrchr(src, c));
// 	printf("ft_strrchr %s\n", ft_strcrhr(src, c));
// }
