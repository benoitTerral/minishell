/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:59:35 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 10:20:44 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "alloc_mem/alloc_mem.h"
# include "print/print.h"
# include "parsing/parsing.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	is_whitespace(char c);

#endif