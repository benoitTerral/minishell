/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:13:00 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/03 11:19:27 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*c;

	c = pointer;
	while (count--)
	{
		*c = value;
		c++;
	}
	return (pointer);
}
/*
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char DuplicateString[255];
    memset(&DuplicateString,'*',50);
    DuplicateString[50] = 0;
    printf("DuplicateString = %s\n",DuplicateString);
    return 0;
}*/
