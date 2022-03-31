/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:19:58 by bterral           #+#    #+#             */
/*   Updated: 2021/11/14 13:16:26 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_itoa_length(int nbr);

static size_t	get_itoa_length(int n)
{
	size_t			count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count++;
		nb = n * (-1);
	}
	else
		nb = (unsigned int)n;
	while ((nb / 10) > 0)
	{
		count++;
		nb = nb / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	nb;

	str_len = get_itoa_length(n);
	str = (char *)malloc(sizeof(*str) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len--] = '\0';
	nb = 0;
	if (n == 0)
		str[str_len] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = n * (-1);
	}
	else if (n > 0)
		nb = (unsigned int)n;
	while (nb != 0)
	{
		str[str_len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
