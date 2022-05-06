/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:17:41 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/06 15:18:24 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_sig(void (*sig_fonction)(int))
{
	signal(SIGINT, sig_fonction);
	signal(SIGQUIT, sig_fonction);
}
