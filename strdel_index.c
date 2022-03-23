/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdel_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:36:12 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 13:21:42 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
/*
int main()
{
	char	*str = NULL;

	str = ft_strdup("Salut_jesuis");
	printf("AVANT=%s\n", str);
	strdel_index(&str, 5);
	printf("APRES=%s\n", str);
	free(str);
}*/
