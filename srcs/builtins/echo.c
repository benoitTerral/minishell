/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:48:57 by bterral           #+#    #+#             */
/*   Updated: 2022/04/05 14:04:10 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	echo_argument(t_cmd *cmd)
{
	int	i;

	if (cmd->str[1] && ft_strncmp(cmd->str[1], "-n", 2) == 0)
	{
		i = 2;
		while (cmd->str[1][i])
		{
			if (cmd->str[1][i] != 'n')
				return (0);
			i++;
		}
		i = 2;
		while (cmd->str[i])
		{
			printf("%s", cmd->str[i]);
			if (i < (cmd->nb_of_arguments - 1))
				printf(" ");
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo(t_cmd *cmd)
{
	int	i;

	if (echo_argument(cmd))
		return (1);
	i = 1;
	while (cmd->str[i])
	{
		printf("%s", cmd->str[i]);
		if (i == (cmd->nb_of_arguments - 1))
			printf("\n");
		else
			printf(" ");
		i++;
	}
	return (1);
}
