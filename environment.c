/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:52 by bterral           #+#    #+#             */
/*   Updated: 2022/03/23 16:03:50 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

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

t_env	*add_env_element(t_env *head, char *str)
{
	char	**split;
	t_env	*new;

	split = ft_split(str, '=');
	new = ft_env_new(split[0], split[1]);
	free(split);
	if (!new)
		return (NULL);
	ft_envadd_back(&head, new);
	return (new);
}

t_env	*init_env_var(char **envp)
{
	char	**split_tmp;
	t_env	*head;
	t_env	*tmp;

	split_tmp = ft_split(*envp, '=');
	head = ft_env_new(split_tmp[0], split_tmp[1]);
	free(split_tmp);
	if (!head)
		return (NULL);
	envp++;
	while(*envp)
	{
		tmp = add_env_element(head, *envp);
		envp++;
	}
	return (head);
}

// int main(int argc ,char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	init_environment_variable(envp);
// 	return (0);
// }