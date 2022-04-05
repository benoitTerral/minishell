/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:00 by bterral           #+#    #+#             */
/*   Updated: 2022/04/05 14:37:27 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../alloc_mem/alloc_mem.h"
# include "../lexer/lexer.h"
# include "../parsing/parsing.h"
# include "../print/print.h"

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env t_env;

typedef struct s_data
{
	int				token;
	char			**str;
	int				nbr_arg;
	t_env			*head;
	struct s_data	*next;
}				t_data;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/// to be classified ///
int	is_whitespace(char c);

/// builtsins ///
int 	disable_option(char *str);
int 	is_build_in(t_data *data);
int		echo(t_data *data);
int 	cd(t_data *data);
int 	pwd(void);
int		unset(t_data *data);
int		env(t_data *data);
int		export(t_data *data);
int 	disable_option(char *str);
int 	ft_isalhpa_underscore(int c);
int 	ft_isalhpanum_underscore(int c);
int		is_var_valid(char *str);

/// ENVIRONMENT VARIABLES ///

t_env	*ft_env_new(char *name, char *value);
void	ft_envadd_back(t_env **alst, t_env *new);
t_env	*ft_envlast(t_env *lst);
int		init_env_var(char **envp, t_env **head);
t_env	*free_env_lst(t_env *head);
t_env	*add_env_element(t_env **head, char *str);
void	ft_envdel(t_data *data, char *name);
void	free_env(t_env **head);


#endif