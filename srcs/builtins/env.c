/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:50:06 by bterral           #+#    #+#             */
/*   Updated: 2022/05/02 16:26:05 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	env(t_data *data)
{
	t_env	*current;

	if (data->str[1])
	{
		if (disable_option(data->str[1], "env"))
			return (1);
		else
		{
			ft_dprintf(2, "env: %s: no such file or directory\n", data->str[1]);
			return (g_ret_sig = 127);
		}
	}
	current = data->head;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
	return (0);
}
