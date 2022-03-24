/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:14:24 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/09 10:04:34 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	int	i;

	i = 0;
	if (!ft_strlen(search))
		return ((char *) &str[i]);
	while (str[i] && len && (i + ft_strlen(search) <= len))
	{
		if (ft_strncmp(&str[i], search, ft_strlen(search)) == 0)
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Bar";
    char	*ptr;

    ptr = strnstr(largestring, smallstring, 11);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring, smallstring, 11);
	printf("%s\n", ptr);
	ptr = strnstr(largestring, smallstring, 9);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring, smallstring, 9);
	printf("%s\n", ptr);
	ptr = strnstr(largestring, smallstring, 20);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring, smallstring, 20);
	printf("%s\n", ptr);
	ptr = strnstr(largestring, smallstring, 0);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring, smallstring, 0);
	printf("%s\n", ptr);
	printf("\n");

	const char *largestring1 = "Salut /-trouvemoi-/ coucou";
	const char *smallstring1 = "/-";
	ptr = strnstr(largestring1, smallstring1, 8);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring1, smallstring1, 8);
	printf("%s\n", ptr);
	ptr = strnstr(largestring1, smallstring1, 7);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring1, smallstring1, 7);
	printf("%s\n", ptr);
	ptr = strnstr(largestring1, smallstring1, 6);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring1, smallstring1, 6);
	printf("%s\n", ptr);
	ptr = strnstr(largestring1, smallstring1, 5);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring1, smallstring1, 5);
	printf("%s\n", ptr);
	const char *largestring2 = "Salut /-trouvemoi-/ coucou";
	const char *smallstring2 = "";
	ptr = strnstr(largestring2, smallstring2, 3);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring2, smallstring2, 3);
	printf("%s\n", ptr);
}
*/
