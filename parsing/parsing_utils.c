/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:28:55 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 18:27:59 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	strdel_index(char **str, int index)
{
	char	*temp;
	char	*end;

	end = ft_substr(*str, index + 1, ft_strlen(*str) - index);
	str[0][index] = '\0';
	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(temp, end);
	free(temp);
	free(end);
}
