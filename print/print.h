/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:51 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/12 13:39:07 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../includes/minishell.h"

/*---color---*/

# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"

# define MINISHELL_C	"\033[0;34mMin\033[0;37miSh\033[0;31mell\033[0;37m $ "
# define MINISHELL		"MiniShell $ "

typedef struct s_data	t_data;

/*---print.c---*/

void	printsplit(char **split);
void	printdata(t_data *lexer);
/*void	print_execution_table(t_exec *exec, int nbr_cmd);*/

#endif