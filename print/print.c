/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:33 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 10:32:46 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_prompter(void)
{
	dprintf(STDOUT_FILENO, "%sM%si%sn%si%sS", WHITE, RED, GREEN, YELLOW, BLUE);
	dprintf(STDOUT_FILENO, "%sh%se%sl%sl%s$ ", WHITE, RED, GREEN, YELLOW,
		WHITE);
}
