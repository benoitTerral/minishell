/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:19 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/11 19:43:21 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n--)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s[] = {0, 1, 2, 3, 4 ,5};

	printf("%s\n", ft_memchr(s, 2 + 256, 3));
	printf("%s\n", memchr(s, 2 + 256, 3));
//	printf("%s\n", ft_memchr("salut slfh xsakb", ' ', 15));
//	printf("%s\n", memchr("salut slfh xsakb", ' ', 15));
}*/
