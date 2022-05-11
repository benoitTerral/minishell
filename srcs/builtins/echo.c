/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:48:57 by bterral           #+#    #+#             */
/*   Updated: 2022/05/11 16:24:31 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	valid_argument(char *str)
{
	int	i;

	(void)i;
	if (str && ft_strncmp(str, "-n", 2) == 0)
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo_argument(t_data *data)
{
	int	i;

	i = 1;
	if (!valid_argument(data->str[i]))
		return (0);
	i++;
	while (data->str[i] && valid_argument(data->str[i]))
		i++;
	while (data->str[i])
	{
		ft_dprintf(1, "%s", data->str[i]);
		if (i < (data->nbr_arg - 1))
			ft_dprintf(1, " ");
		i++;
	}
	return (1);
}

int	echo(t_data *data)
{
	int	i;

	if (echo_argument(data))
		return (0);
	i = 1;
	while (data->str[i])
	{
		ft_dprintf(1, "%s", data->str[i]);
		if (i != (data->nbr_arg - 1))
			ft_dprintf(1, " ");
		i++;
	}
	ft_dprintf(1, "\n");
	return (0);
}
