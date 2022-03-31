/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:45:24 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 13:57:33 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_variable(char c, va_list	args, int fd)
{
	int	len;

	if (c == 'c')
		len = handle_char(va_arg(args, int), fd);
	else if (c == 's')
		len = handle_string(va_arg(args, char *), fd);
	else if (c == 'x')
		len = ft_putnbr_base_uint(va_arg(args, unsigned int), LOWER, fd);
	else if (c == 'X')
		len = ft_putnbr_base_uint(va_arg(args, unsigned int), UPPER, fd);
	else if (c == 'p')
	{
		len = 2;
		ft_putstr_fd("0x", fd);
		len += ft_putnbr_base_ll(va_arg(args, unsigned long long), LOWER, fd);
	}
	else if (c == 'd' || c == 'i')
		len = handle_putint(va_arg(args, int), fd);
	else if (c == 'u')
		len = handle_putunsignedint(va_arg(args, unsigned int), fd);
	else if (c == '%' || c == '\n')
		len = handle_char(c, fd);
	else
		len = 0;
	return (len);
}

int	get_print_size(const char *str, va_list args, int fd)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += handle_variable(str[i], args, fd);
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_dprintf(int fd, const char *input, ...)
{
	va_list	args;
	int		size;

	va_start(args, input);
	size = get_print_size(input, args, fd);
	va_end(args);
	return (size);
}
