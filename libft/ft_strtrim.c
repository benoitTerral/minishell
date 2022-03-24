/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:04:39 by laraujo           #+#    #+#             */
/*   Updated: 2022/01/11 16:01:11 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	str_search(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	k = 0;
	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	if (*s1 == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (str_search(set, s1[i]))
		i++;
	if (i > j - 1)
		return (ft_strdup(""));
	while (str_search(set, s1[j - 1]))
		j--;
	result = malloc ((j - i + 1) * sizeof(char));
	if (result == 0)
		return (0);
	while (i <= j - 1)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}
/*
int	main()
{
	char *s1 = "   \t  \n\n  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\n  ";
//	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("%s", ret);
	free(ret);
}*/
