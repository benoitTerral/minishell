/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:28:09 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/12 10:37:19 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int search_char)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if ((char) search_char == 0)
		return ((char *)&str[i]);
	while (i-- != 0)
	{
		if (str[i] == (char) search_char)
			return ((char *)&str[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%s\n", ft_strrchr("salut slfh xsakb", ' '));
	printf("%s\n", strrchr("salut slfh xsakb", ' '));
	printf("%s ", ft_strrchr("slut", 97));
	printf("%s ", strrchr("slut", 97));
	printf("%s ", ft_strrchr("", 97));
	printf("%s ", strrchr("", 97));
	printf("%s ", ft_strrchr("salut", 0));
	printf("%s ", strrchr("salut", 0));
}*/
