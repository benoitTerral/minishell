/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:51:07 by bterral           #+#    #+#             */
/*   Updated: 2022/04/06 16:31:48 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pwd(t_data *data)
{
	char	path[PATH_MAX];

	if (data->str[1] && disable_option(data->str[1], "pwd"))
		return (1);
	getcwd(path, PATH_MAX);
	printf("%s\n", path);
	return (1);
}
