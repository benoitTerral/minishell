/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:51:07 by bterral           #+#    #+#             */
/*   Updated: 2022/03/26 11:51:13 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

int pwd(void)
{
	char path[PATH_MAX];

	getcwd(path, PATH_MAX);
	printf("%s\n", path);
	return (1);
}