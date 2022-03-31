/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:23:44 by bterral           #+#    #+#             */
/*   Updated: 2021/11/15 16:28:31 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	s_len;
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	sub_len = 0;
	s_len = ft_strlen(s);
	while (sub_len < len && *(s + sub_len) != '\0' && start < s_len)
		sub_len++;
	output = (char *)malloc(sizeof(*s) * (sub_len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		*(output + i) = *(s + start + i);
		i++;
	}
	*(output + i) = '\0';
	return (output);
}
