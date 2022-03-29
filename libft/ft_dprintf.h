/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:42:06 by bterral           #+#    #+#             */
/*   Updated: 2022/03/26 11:42:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"

int		ft_dprintf(int fd, const char *input, ...);
int		get_print_size(const char *str, va_list args, int fd);
int		handle_variable(char c, va_list	args, int fd);
int		handle_char(char c, int fd);
int		handle_string(char *str, int fd);
int		handle_putint(int nb, int fd);
int		handle_putunsignedint(unsigned int nb, int fd);
int		ft_putnbr_base_ll(unsigned long long nbr, char *base, int fd);
int		ft_putnbr_base_uint(unsigned int nbr, char *base, int fd);

#endif 
