/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:00 by bterral           #+#    #+#             */
/*   Updated: 2022/03/28 17:55:58 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_env t_env;

typedef struct s_cmd
{
	char	**str;
	int		token;
	int		nb_of_arguments;
	t_env	*head;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/// BUILD IN FUNCTIONS ///

int 	disable_option(char *str);
int 	is_build_in(t_cmd *cmd);
int		echo(t_cmd *cmd);
int 	cd(t_cmd *cmd);
int 	pwd(void);
int		unset(t_cmd *cmd);
int		env(t_cmd *cmd);
int		export(t_cmd *cmd);
int 	disable_option(char *str);
int 	ft_isalhpa_underscore(int c);
int 	ft_isalhpanum_underscore(int c);
int		is_var_valid(t_env **head, char *str);

/// ENVIRONMENT VARIABLES ///

t_env	*ft_env_new(char *name, char *value);
void	ft_envadd_back(t_env **alst, t_env *new);
t_env	*ft_envlast(t_env *lst);
void	init_env_var(char **envp, t_env **head);
t_env	*free_env_lst(t_env *head);
t_env	*add_env_element(t_env **head, char *str);
void	ft_envdel(t_cmd *cmd, char *name);


#endif