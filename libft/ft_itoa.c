/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:38:41 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/11 16:28:48 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(int n)
{
	int	len_nbr;

	len_nbr = 0;
	if (n < 0)
		len_nbr++;
	while (n)
	{
		n = n / 10;
		len_nbr++;
	}
	return (len_nbr);
}

static long int	ft_minus(long int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int			i;
	int			len_nbr;
	char		*nbr_str;
	long int	l_n;

	l_n = n;
	len_nbr = ft_len_nbr(l_n);
	if (!len_nbr)
		len_nbr = 1;
	i = len_nbr;
	nbr_str = malloc((len_nbr + 1) * sizeof(char));
	if (!nbr_str)
		return (0);
	if (l_n < 0)
		nbr_str[0] = '-';
	l_n = ft_minus(l_n);
	if (l_n == 0)
		*nbr_str = '0';
	while (l_n)
	{
		nbr_str[i-- - 1] = l_n % 10 + '0';
		l_n /= 10;
	}
	nbr_str[len_nbr] = '\0';
	return (nbr_str);
}
/*
int	main()
{
	printf("%s\n" , ft_itoa(0));
	printf("%s\n" , ft_itoa(123));
	printf("%s\n" , ft_itoa(-123));
}*/
