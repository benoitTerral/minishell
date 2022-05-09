/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:52 by bterral           #+#    #+#             */
/*   Updated: 2022/05/09 15:34:07 by laraujo          ###   ########lyon.fr   */
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

int	error_free_env(t_env **head)
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

char	**env_lst_to_char(t_env *head)
{
	int		i;
	int		j;
	t_env	*ptr;
	char	**output;
	char	*tmp1;

	i = 0;
	ptr = head;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	output = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	ptr = head;
	while (j < i)
	{
		tmp1 = ft_strjoin(ptr->name, "=");
		output[j] = ft_strjoin(tmp1, ptr->value);
		free(tmp1);
		ptr = ptr->next;
		j++;
	}
	output[j] = NULL;
	return (output);
}
