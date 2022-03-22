/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:14:32 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/12 13:45:16 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char addOne(unsigned int i, char c) {return (i + c);}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;
	int		i;

	if (!s)
		return (0);
	i = -1;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (++i < len)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char	*result;
	char	*str = {"salut"};

	printf("%s\n", str);
	result = ft_strmapi(str, &addOne);
	printf("%s\n", result);
	free (result);
	return (0);
}*/
