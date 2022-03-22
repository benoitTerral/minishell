/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:35 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/21 11:55:44 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	if (s1 == 0 || s2 == 0)
		return (0);
	dest = 0;
	len = ft_strlen(s2) + ft_strlen(s1) + 1;
	dest = malloc((len) * sizeof(char));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, (len));
	ft_strlcat(dest, s2, (len));
	return (dest);
}
/*
int	main()
{
	char *s1 = "my favorite animal is";
	char *s2 = " test";
	printf("%s\n", ft_strjoin(s1, s2));
}
*/