/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:33:28 by bterral           #+#    #+#             */
/*   Updated: 2021/11/09 15:19:31 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (num == 0)
		return (0);
	i = 0;
	str1 = (const unsigned char *)ptr1;
	str2 = (const unsigned char *)ptr2;
	while (*str1 == *str2 && i < (num - 1))
	{
		str1++;
		str2++;
		i++;
	}
	return (*str1 - *str2);
}
