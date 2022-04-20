/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:00 by bterral           #+#    #+#             */
/*   Updated: 2022/04/19 17:32:58 by bterral          ###   ########.fr       */
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
# include <fcntl.h>

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

typedef struct s_pipe
{
	int	fd[2];
}			t_pipe;

typedef struct s_exec
{
	char		***cmd;
	t_pipe		pipe;
	int			fd_in;
	int			fd_out;
	pid_t		pid;
}	t_exec;

/// to be classified ///
int	is_whitespace(char c);

/// builtsins ///
int 	is_build_in(t_data *data);
int		echo(t_data *data);
int 	cd(t_data *data);
int 	pwd(t_data *data);
int		unset(t_data *data);
int		env(t_data *data);
int		export(t_data *data);
int		disable_option(char *str, char *funct);
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

/// EXECUTION ///

int	execute_command(t_data **start);
int populate_exec(t_exec *exec, t_data **data);
int nbr_of_commands(t_data **start);

#endif