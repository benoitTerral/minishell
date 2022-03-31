/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:26:01 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 13:57:49 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_putint(int nb, int fd)
{
	int			len;

	len = 0;
	if (nb == -2147483648)
		return (handle_string("-2147483648", fd));
	if (nb < 0)
	{
		len += handle_char('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		len += handle_putint(nb / 10, fd);
		nb = nb % 10;
	}
	len += handle_char(nb + '0', fd);
	return (len);
}

int	handle_putunsignedint(unsigned int nb, int fd)
{
	int			len;

	len = 0;
	if (nb > 9)
	{
		len += handle_putunsignedint(nb / 10, fd);
		nb = nb % 10;
	}
	len += handle_char(nb + '0', fd);
	return (len);
}
