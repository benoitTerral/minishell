/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:18:37 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/12 11:06:51 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	dst = 0;
	i = 0;
	if (s == 0)
		return (0);
	if (len < ft_strlen(s))
		dst = malloc((len + 1) * sizeof(char));
	else
		dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (0);
	if (start >= ft_strlen(s))
	{
		dst[0] = '\0';
		return (&dst[0]);
	}
	while (s[start] && len--)
	{
		dst[i++] = s[start++];
	}
	dst[i] = '\0';
	return (&dst[0]);
}
/*
#include <stdio.h>
int	main()
{
	char *str = "i just want this part #############";
	size_t size = 20;
	char *ret = ft_substr(str, 5, size);
	printf("TEST \n");
	printf("%s",ret);
	free(ret);
}*/
