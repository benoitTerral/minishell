/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:25 by bterral           #+#    #+#             */
/*   Updated: 2021/11/15 17:48:10 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		needle_len;

	if (*s2 == '\0')
		return ((char *)s1);
	needle_len = ft_strlen(s2);
	i = 0;
	j = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] && s1[i + j] && s1[i + j] == s2[j] && (i + j) < len)
			j++;
		if (j == needle_len)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
