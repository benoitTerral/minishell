/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:26:49 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/04 15:54:35 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if ((unsigned char)*str1 != (unsigned char)*str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int array1 [] = { 54, 85, 80, 63, 21 };
    int array2 [] = { 54, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;
	char	*s1 = "Sa";
	char	*s2 = "SA";

    printf("%d, ", memcmp( array1, array2, size));
    printf("%d, ", memcmp( array2, array1, size));
    printf("%d, ", memcmp( "sa", "sA", 2));
    printf("%d, ", memcmp( "sa", "sacdf", 10));
    printf("%d, ", memcmp( s1, s2, 2));
    printf("%d\n", memcmp( array1, array1, size));
	printf("%d, ", ft_memcmp( array1, array2, size));
    printf("%d, ", ft_memcmp( array2, array1, size));
    printf("%d, ", ft_memcmp( "sa", "sA", 2));
    printf("%d, ", ft_memcmp( "sa", "sacdf", 10));
    printf("%d, ", ft_memcmp( s1, s2, 2));
    printf("%d\n", ft_memcmp( array1, array1, size));


    return 0;
}*/
