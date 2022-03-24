/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:34:25 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/08 14:22:25 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*temp;
	const unsigned char	*temp2;

	if (dest == 0 && src == 0)
		return (0);
	temp = dest;
	temp2 = src;
	while (count--)
	{
		*temp = *temp2;
		temp++;
		temp2++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;

    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );

    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
}*/
