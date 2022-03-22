/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:25 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/09 10:05:33 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (*src && (dstsize - 1))
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (size);
}
/*
#include <stdio.h>
int	main()
{
	char dst[10];
	const char *src = "salut";

	printf("%lu\n", strlcpy(dst, src, 5));
	printf("%s\n", dst);
	*dst = '\0';
	printf("%lu\n", ft_strlcpy(dst, src, 4));
	printf("%s\n", dst);

	char *c1 = "source";
	char c2[] = "destination";
	char c3[] = "destination";
	printf("6, sour : %lu, %s\n", ft_strlcpy(c2, c1, 5), c2);
	printf("6, source : %lu, %s\n", ft_strlcpy(c3, c1, 8), c3);
}*/
