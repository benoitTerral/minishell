/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:48:57 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 11:16:57 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	echo_argument(t_data *data)
{
	int	i;

	if (data->str[1] && ft_strncmp(data->str[1], "-n", 2) == 0)
	{
		i = 2;
		while (data->str[1][i])
		{
			if (data->str[1][i] != 'n')
				return (0);
			i++;
		}
		i = 2;
		while (data->str[i])
		{
			ft_dprintf(1, "%s", data->str[i]);
			if (i < (data->nbr_arg - 1))
				ft_dprintf(1, " ");
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo_t(t_data *data)
{
	int	i;

	if (echo_argument(data))
		return (1);
	i = 1;
	while (data->str[i])
	{
		ft_dprintf(1, "%s", data->str[i]);
		if (i == (data->nbr_arg - 1))
			ft_dprintf(1, "\n");
		else
			ft_dprintf(1, " ");
		i++;
	}
	return (0);
}
