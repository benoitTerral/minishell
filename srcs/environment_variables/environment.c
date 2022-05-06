/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:52 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 10:07:49 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*my_getenv(char *var_name, t_env **head)
{
	t_env	*ptr;
	char	*var_value;

	var_value = NULL;
	ptr = *(head);
	while (ptr)
	{
		if (ft_strcmp(var_name, ptr->name))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (var_value);
}

void	free_env(t_env **head)
{
	t_env	*current;
	t_env	*next;

	if (!(*head))
		return ;
	current = (*head);
	while (current)
	{
		next = current->next;
		free(current->name);
		current->name = NULL;
		if (current->value)
		{
			free(current->value);
			current->value = NULL;
		}
		free(current);
		current = next;
	}
}

t_env	*add_env_element(t_env **head, char *str)
{
	char	**split;
	t_env	*new;

	split = ft_split(str, '=');
	new = ft_env_new(split[0], split[1]);
	free(split);
	if (!new)
		return (NULL);
	ft_envadd_back(head, new);
	return (new);
}

static int	error_free_env(t_env **head)
{
	t_env	*current;
	t_env	*next;

	if (!(*head))
		return (1);
	current = (*head);
	while (current)
	{
		next = current->next;
		free(current->name);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	return (1);
}

int	init_env_var(char **envp, t_env **head)
{
	char	**split;
	t_env	*env_ptr;

	while (*envp)
	{
		split = ft_split(*envp, '=');
		if (!split)
			return (1);
		env_ptr = ft_env_new(split[0], split[1]);
		free(split);
		if (!env_ptr)
			error_free_env(head);
		if (*head == NULL)
			*head = env_ptr;
		else
			ft_envadd_back(head, env_ptr);
		envp++;
	}
	return (0);
}
