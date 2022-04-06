/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:56:08 by bterral           #+#    #+#             */
/*   Updated: 2022/04/06 11:40:33 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int disable_option(char *str, char *funct)
{
	if (str[0] == '-')
	{
		ft_dprintf(2, "%s: -%c : invalid option", funct, str[1]);
		return (1);
	}
	else 
		return (0);
}

int ft_isalhpa_underscore(int c)
{
	if (ft_isalpha(c))
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int ft_isalhpanum_underscore(int c)
{
	if (ft_isalnum(c))
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int	is_var_valid(char *str)
{
	if (ft_isalhpa_underscore(str[0]) == 0)
		return (0);
	while (*str)
	{
		if (ft_isalhpanum_underscore(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
