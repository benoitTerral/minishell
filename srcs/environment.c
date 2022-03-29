/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:52 by bterral           #+#    #+#             */
/*   Updated: 2022/03/29 13:40:39 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

t_env	*free_env_lst(t_env *head)
{
	t_env	*current;
	t_env	*next;

	current = head;
	while (current)
	{
		next = current->next;
		current->name = NULL;
		current->value = NULL;
		free(current);
		current = next;
	}
	return (NULL);
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

void	init_env_var(char **envp, t_env **head)
{
	char	**split;
	t_env	*env_ptr;

	while (*envp)
	{
		split = ft_split(*envp, '=');
		//securing malloc
		env_ptr = ft_env_new(split[0], split[1]);
		//securing malloc
		if (*head == NULL)
			*head = env_ptr;
		else
			ft_envadd_back(head, env_ptr);
		envp++;
	}
}
