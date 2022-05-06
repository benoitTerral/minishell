/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:33 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/06 15:42:34 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	printsplit(char **split)
{
	int	j;

	j = 0;
	ft_dprintf(1, "\n");
	while (split[j])
	{
		ft_dprintf(1, "ARG[%d]=%s\n", j, split[j]);
		j++;
	}
	ft_dprintf(1, "ARG[%d]=%s\n", j, split[j]);
}

void	printdata(t_data *lexer)
{
	if (lexer)
	{
		ft_dprintf(1, "\nTOKEN=%d", lexer->token);
		printsplit(lexer->str);
		ft_dprintf(1, "lexer->next=%p\n", lexer->next);
		while (lexer->next)
		{
			lexer = lexer->next;
			ft_dprintf(1, "\nTOKEN=%d", lexer->token);
			printsplit(lexer->str);
			ft_dprintf(1, "lexer->next=%p\n", lexer->next);
		}
	}
}

void	print_execution_table(t_exec *exec, int nbr_cmd)
{
	int	i;
	int	j;

	i = 0;
	ft_dprintf(1, "\n Execution table \n");
	while (i < nbr_cmd)
	{
		ft_dprintf(1, "\nCommand number : %d\n", i);
		j = 0;
		while (exec[i].cmd[0][j])
		{
			ft_dprintf(1, "exec[i].cmd[0][%d]: %s\n", j, exec[i].cmd[0][j]);
			j++;
		}
		ft_dprintf(1, "fd_in: %d\n", exec[i].fd_in);
		ft_dprintf(1, "fd_out: %d\n", exec[i].fd_out);
		i++;
	}
}
