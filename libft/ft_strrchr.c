/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:17:32 by bterral           #+#    #+#             */
/*   Updated: 2021/11/09 15:32:14 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	size_t	len_str;
	char	c;

	len_str = ft_strlen(str);
	c = (char)character;
	if (str[len_str] == c)
		return ((char *)(&str[len_str]));
	while (len_str > 0)
	{
		if (str[len_str - 1] == c)
			return ((char *)(&str[len_str - 1]));
		len_str--;
	}
	return (NULL);
}
