/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:00:49 by bterral           #+#    #+#             */
/*   Updated: 2022/05/25 10:10:30 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *str)
{
	char	*output;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	output = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (str[i])
	{
		output[i] = ft_tolower(str[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
