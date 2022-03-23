/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:13:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 19:30:29 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_mem.h"

void	ft_free(char **pt)
{
	if (!*pt || !pt)
		return ;
	free(*pt);
	*pt = NULL;
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
