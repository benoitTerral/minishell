/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:56:22 by bterral           #+#    #+#             */
/*   Updated: 2021/11/15 17:41:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 ||!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		*(output + i) = *(s1 + i);
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		*(output + i) = *(s2 + (i - s1_len));
		i++;
	}
	*(output + i) = 0;
	return (output);
}
