/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:21 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/06 14:56:29 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define ERROR_EXIT_NUM "MiniShell: exit: numeric argument required\n"

static int	ft_atoi2(char *str, long long *result)
{
	int	sign;

	*result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		*result = *result * 10 + *str - '0';
		str++;
	}
	if (*str != '\0' && !is_whitespace(*str) && !ft_isdigit(*str))
	{
		ft_dprintf(STDERR_FILENO, RED ERROR_EXIT_NUM WHITE);
		*result = -1;
		return (-1);
	}
	*result = *result * sign;
	return (0);
}

int	my_exit(t_data **data)
{
	long long	res;
	long long	buf;

	if ((*data)->nbr_arg > 2)
		return (ft_dprintf(STDERR_FILENO,
				RED"MiniShell: exit: too many arguments\n"WHITE));
	if ((*data)->nbr_arg == 1)
	{
		ft_dprintf(STDOUT_FILENO, "%se%sxi%st%s\n", BLUE, WHITE, RED, WHITE);
		free_env(&(*data)->head);
		ft_lstclear_data(data);
		exit (g_ret_sig);
	}
	if (ft_atoi2((*data)->str[1], &res))
		return (-1);
	buf = res % 256;
	if (res < 0)
		buf = 256 + buf;
	ft_dprintf(STDOUT_FILENO, "%se%sxi%st%s\n", BLUE, WHITE, RED, WHITE);
	free_env(&(*data)->head);
	ft_lstclear_data(data);
	exit (buf);
}
