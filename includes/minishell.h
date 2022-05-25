/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:00 by bterral           #+#    #+#             */
/*   Updated: 2022/05/25 10:30:44 by bterral          ###   ########.fr       */
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
# include <signal.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>

extern int				g_ret_sig;

typedef struct s_env	t_env;

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

typedef struct s_exec
{
	char		***cmd;
	int			fd_in;
	int			fd_out;
	pid_t		pid;
	char		*cmd_full_path;
	int			is_builtin;
	int			is_cmd;
	t_data		*data;
}	t_exec;

typedef struct s_termios
{
	struct termios	old_term;
	struct termios	new_term;
}	t_termios;

typedef struct s_norm
{
	char	*delim;
	int		i;
	int		quote;
}	t_norm;

typedef struct s_pipe_fd
{
	int	fd[2];
	int	*fd_tmp;
	int	nbr_cmd;
}	t_p;

/// builtsins ///
int		is_build_in(t_data **data, int nbr_cmd, t_termios *term);
int		is_build_in_bool(char *cmd);
int		echo(t_data *data);
int		echo_argument(t_data *data);
int		valid_argument(char *str);
int		cd(t_data *data);
int		pwd(t_data *data);
int		unset(t_data *data);
int		env(t_data *data);
int		export(t_data *data);
int		my_exit(t_data **data);
int		disable_option(char *str, char *funct);
int		ft_isalhpa_underscore(int c);
int		ft_isalhpanum_underscore(int c);
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
void	ft_envdel_node(t_env *env);
char	*my_getenv(char *var_name, t_env **head);
int		init_from_bash(char **envp, t_env **head);
int		update_shlvl(t_env **head);
int		error_free_env(t_env **head);
char	**env_lst_to_char(t_env *head);
int		shlvl_exists(t_env **head);
int		pwd_missing(t_env **head);

/// EXECUTION ///

int		execute_command(t_data **start, t_env **env, t_termios *term);
int		populate_exec(t_exec *exec, t_data **data);
char	**get_paths(t_env **head);
char	*get_cmd(t_exec	exec, char **envp);
int		child_process(t_exec *exec, int nbr_pipes, t_termios *term);
int		nbr_of_cmd(t_data **start);
int		populate_exec_table(t_data *data, t_exec *exec, int nbr_pipes,
			t_env **env);
void	print_execution_table(t_exec *exec, int nbr_pipes);
int		populate_exec_table(t_data *data, t_exec *exec, int nbr_pipes,
			t_env **env);
void	get_abs_path_cmd(t_exec *exec, int nbr_pipes, char **envp);
int		wait_all_pid(t_exec *exec, int nbr_pipes);
void	free_paths(char **strings);
int		get_here_doc(char *delim, t_env **env);
void	manage_fd_in(t_exec *exec, int i, t_p p_fd);
void	manage_fd_out(t_exec *exec, int i, t_p p_fd);
void	free_paths(char **strings);
void	free_all(char **envp, t_exec *exec);
void	execute_child_process(t_exec *exec, int i, t_p p_fd, t_termios *term);
void	initialize_pipe_structure(t_p *p_fd, int nbr_pipes);
void	close_swap_fds(int fd_0, int fd_1, int *fd_tmp);
void	error_pid(int fd_0, int fd_1);
void	close_in_out(int fd_in, int fd_out);
void	disable_signal_minishellception(char *str);

/// SIGNAUX ///

void	set_sig(void (*sig_fonction)(int));
void	sig_handler_prompt(int sig);
void	sig_handler_here(int sig);
void	sig_handler_child(int sig);
void	sig_handler_disable(int sig);
void	sig_handler_m(int sig);

#endif