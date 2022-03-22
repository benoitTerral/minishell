/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:45:31 by bterral           #+#    #+#             */
/*   Updated: 2021/11/14 13:13:51 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	if (num == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < num && str1[i] && str2[i])
		i++;
	if (i == num && num != 0)
		return (0);
	else
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
