/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/04/19 16:45:01 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_build_in(t_data **data)
{
	if (ft_strcmp((*data)->str[0], "echo"))
		return (echo(*data));
	else if (ft_strcmp((*data)->str[0], "cd"))
		return (cd(*data));
	else if (ft_strcmp((*data)->str[0], "pwd"))
		return (pwd(*data));
	else if (ft_strcmp((*data)->str[0], "export"))
		return (export(*data));
	else if (ft_strcmp((*data)->str[0], "unset"))
		return (unset(*data));
	else if (ft_strcmp((*data)->str[0], "env"))
		return (env(*data));
	else if (ft_strcmp((*data)->str[0], "exit"))
		return (my_exit(data));
	return (0);
}
