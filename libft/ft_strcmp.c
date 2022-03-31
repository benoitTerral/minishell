/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:26:35 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 13:58:45 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (ft_strlen(str1) == ft_strlen(str2))
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
