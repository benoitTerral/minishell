/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:50:39 by bterral           #+#    #+#             */
/*   Updated: 2022/04/05 14:04:24 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset(t_cmd *cmd)
{
	int	i;

	if (disable_option(cmd->str[1]))
		return (1);
	i = 1;
	if (!cmd->str[i])
		return (0);
	while (cmd->str[i])
	{
		if (is_var_valid(&cmd->head, cmd->str[i]) == 0)
			ft_dprintf(2, "export: %s : not a valid identifier\n", cmd->str[i]);
		ft_envdel(cmd, cmd->str[i]);
		i++;
	}
	return (0);
}