/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:18:47 by bterral           #+#    #+#             */
/*   Updated: 2022/04/06 16:40:05 by bterral          ###   ########.fr       */
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

	lst = NULL;
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

void	ft_envdel_node(t_env *env)
{
	free(env->name);
	env->name = NULL;
	free(env->value);
	env->value = NULL;
	env->next = NULL;
	free(env);
}

void	ft_envdel(t_data *data, char *name)
{
	t_env	*previous;
	t_env	*current;

	previous = data->head;
	if (ft_strcmp(previous->name, name))
	{
		data->head = previous->next;
		ft_envdel_node(previous);
		return ;
	}
	current = previous->next;
	while (current)
	{
		if (ft_strcmp(current->name, name))
		{
			previous->next = current->next;
			ft_envdel_node(current);
			return ;
		}
		previous = previous->next;
		current = current->next;
	}
}
