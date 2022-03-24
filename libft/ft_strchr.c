/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:08 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/21 15:26:16 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int search_char)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) search_char)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char) search_char)
		return ((char *)&str[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%s\n", ft_strchr("salut slfh xsakb", ' '));
	printf("%s\n", strchr("salut slfh xsakb", ' '));
	printf("%s ", ft_strchr("slut", 97));
	printf("%s ", strchr("slut", 97));
	printf("%s ", ft_strchr("", 97));
	printf("%s ", strchr("", 97));
	printf("%s ", ft_strchr("salut", 0));
	printf("%s ", strchr("salut", 0));
}*/
