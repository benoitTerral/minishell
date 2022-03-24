/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:41:16 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/12 10:45:58 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!*s1 && *s2 && n > 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (n-- && (*s1 || *s2))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {

	ft_strncmp("", "1", 0);
}
    printf("%d\n", ft_strncmp("test", "testss", 7));
    printf("%d\n", strncmp("test", "testss", 7));

    printf("%d\n", ft_strncmp("vA", "va", 2));
    printf("%d\n", strncmp("vA", "va", 2));
    printf("%d\n", strncmp("va", "va", 4));
    printf("%d\n", ft_strncmp("va", "va", 4));
	char * vA = "";
	char * va = "a";
    printf("%d\n", strncmp(vA, va, 2));
    printf("%d\n", ft_strncmp(vA, va, 2));
    printf("%d\n", strncmp(vA, vA, 4));
    printf("%d\n", ft_strncmp(vA, vA, 4));

	printf("\nTest de ft_strncmp :\n");
	printf("0 : %d\n", ft_strncmp("4", "", 1));
	printf("0 : %d\n", strncmp("4", "", 1));
	printf("-50 : %d\n", ft_strncmp("test", "test2", 5));
	printf("0 : %d\n", ft_strncmp("test", "test2", 4));
	printf("128 : %d\n", ft_strncmp("\200", "\0", 4));
	printf("1 : %d\n", ft_strncmp("tesu", "test", 6));


    return 0;
}*/
