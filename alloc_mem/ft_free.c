/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:13:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/04 15:06:29 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_mem.h"

void	*ft_free(char **pt)
{
	if (!*pt || !pt)
		return (NULL);
	free(*pt);
	*pt = NULL;
	return (NULL);
}

void	ft_free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split[j]);
	free(split);
}
