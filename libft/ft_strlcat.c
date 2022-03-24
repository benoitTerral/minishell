/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:18:17 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/08 19:13:00 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[j] && (--dstsize - i) && (dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>
int	main()
{
	char dst[10] = "salut";
	const char *src = "";

	printf("%lu\n", ft_strlcat(dst, src, 10));
	printf("%s\n", dst);
	*dst = '\0';
	printf("%lu\n", ft_strlcat(dst, src, 6));
	printf("%s\n", dst);
	printf("\nTest de ft_strlcat :\n");
	char *c1 = "source";
	char d2[100] = "destination";
	char d3[100] = "destination";
	char d4[100] = "destination";
	char d5[100] = "dest";
	char d6[100] = "dest";
	char d7[100] = "dest";
	printf("11, destination : %lu, %s\n", ft_strlcat(d2, c1, 5), d2);
	printf("14, destination : %lu, %s\n", ft_strlcat(d3, c1, 8), d3);
	printf("17, destinations : %lu, %s\n", ft_strlcat(d4, c1, 13), d4);
	printf("10, dest : %lu, %s\n", ft_strlcat(d5, c1, 5), d5);
	printf("10, destsou: %lu, %s\n", ft_strlcat(d6, c1, 8), d6);
	printf("10, destsource : %lu, %s\n", ft_strlcat(d7, c1, 13), d7);
}*/
