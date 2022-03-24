/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:33 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 15:06:51 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_prompter(void)
{
	dprintf(STDOUT_FILENO, "%sMin%siS", BLUE, WHITE);
	dprintf(STDOUT_FILENO, "h%sell%s $ ", RED, WHITE);
}

void	printsplit(char **split)
{
	int	j;

	j = 0;
	printf("\n");
	while (split[j])
	{
		printf("ARG[%d]=%s\n", j, split[j]);
		j++;
	}
	printf("ARG[%d]=%s\n", j, split[j]);
}
