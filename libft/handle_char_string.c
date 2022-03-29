/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:51:15 by bterral           #+#    #+#             */
/*   Updated: 2022/03/26 11:41:42 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	handle_char(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	handle_string(char *str, int fd)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, fd);
	}
	else
	{
		ft_putstr_fd("(null)", fd);
		len = ft_strlen("(null)");
	}
	return (len);
}
