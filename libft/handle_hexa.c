/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:07:56 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 13:57:55 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_ll(unsigned long long nbr, char *base, int fd)
{
	unsigned long long	size;
	int					count;

	count = 0;
	size = (unsigned long int)ft_strlen(base);
	if (nbr >= size)
	{
		count += ft_putnbr_base_ll(nbr / size, base, fd);
		nbr = nbr % size;
	}
	ft_putchar_fd(base[nbr], fd);
	count++;
	return (count);
}

int	ft_putnbr_base_uint(unsigned int nbr, char *base, int fd)
{
	unsigned int	size;
	int				count;

	count = 0;
	size = (unsigned long int)ft_strlen(base);
	if (nbr >= size)
	{
		count += ft_putnbr_base_uint(nbr / size, base, fd);
		nbr = nbr % size;
	}
	ft_putchar_fd(base[nbr], fd);
	count++;
	return (count);
}
