/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:51 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 17:50:25 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../minishell.h"

/*---color---*/

# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"

# define MINISHELL	"\033[0;34mMin\033[0;37miSh\033[0;31mell\033[0;37m $ "

// "%sMin%siS", BLUE, WHITE
// "h%sell%s $ ", RED, WHITE

/*---print.c---*/

void	print_prompter(void);
void	printsplit(char **split);

#endif