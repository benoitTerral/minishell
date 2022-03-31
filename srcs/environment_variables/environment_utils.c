/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:18:47 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 15:15:32 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_env_new(char *name, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new)
	{
		new->name = name;
		new->value = value;
		new->next = NULL;
	}
	if (!new->name || (!new->value && value))
		return (NULL);
	return (new);
}

void	ft_envadd_back(t_env **alst, t_env *new)
{
	t_env	*lst;

	if (*alst)
	{
		if (alst)
		{
			lst = ft_envlast(*alst);
			lst->next = new;
		}
	}
	else
		*alst = new;
}

t_env	*ft_envlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_envdel(t_cmd *cmd, char *name)
{
	t_env	*previous;
	t_env	*current;

	previous = cmd->head;
	if (ft_strcmp(previous->name, name))
	{
		previous->name = NULL;
		previous->value = NULL;
		cmd->head = previous->next;
		free(previous);
		return ;
	}
	current = previous->next;
	while (current)
	{
		if (ft_strcmp(current->name, name))
		{
			previous->next = current->next;
			current->name = NULL;
			current->value = NULL;
			free(current);
			return ;
		}
		previous = previous->next;
		current  = current->next;
	}
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
