/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:08:33 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/02 16:11:42 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main()
{
	printf("%d\n", ft_isascii('?'));
	printf("%d", isascii('?'));
	return(0);
}*/
