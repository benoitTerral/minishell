/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:05:34 by bterral           #+#    #+#             */
/*   Updated: 2021/11/14 10:57:51 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	chara;
	unsigned int	i;

	s = (unsigned char *)src;
	chara = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(s + i) == chara)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
