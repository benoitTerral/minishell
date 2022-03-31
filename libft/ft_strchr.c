/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:02:03 by bterral           #+#    #+#             */
/*   Updated: 2021/11/09 15:31:52 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	char	c;

	c = (char)character;
	while (*str)
	{
		if (*str == c)
			return ((char *)(&*str));
		str++;
	}
	if (*str == c)
		return ((char *)(&*str));
	return (NULL);
}
