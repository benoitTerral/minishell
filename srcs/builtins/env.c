/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:50:06 by bterral           #+#    #+#             */
/*   Updated: 2022/03/29 13:35:58 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

int	env(t_cmd *cmd)
{
	t_env	*current;

	if (cmd->str[1])
	{
		if (disable_option(cmd->str[1]))
			return (1);
		else
		{
			ft_dprintf(2, "env: %s: no such file or directory\n", cmd->str[1]);
			return (1);
		}
	}
	current = cmd->head;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
	return (0);
}
