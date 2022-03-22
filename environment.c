/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:52 by bterral           #+#    #+#             */
/*   Updated: 2022/03/21 16:50:43 by bterral          ###   ########.fr       */
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

	// split = ft_split_piscine(str, "= \t\r");
	split = ft_split(str, '=');
	//seg fault avec fsanitize=address ?
	// if (split[0] && split[1])
	new = ft_env_new(split[0], split[1]);
	// else
	// 	new = ft_env_new(split[0], NULL);
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
	// if (split_tmp[0] && split_tmp[1])
	// if (split_tmp[0] && split_tmp[1])
	head = ft_env_new(split_tmp[0], split_tmp[1]);
	// else
	// 	head = ft_env_new(split_tmp[0], NULL);
	free(split_tmp);
	// else if (split_tmp[0])
	// 	head = ft_env_new(split_tmp[0], NULL);
	// else
	// 	return (NULL);
	if (!head)
		return (NULL);
	envp++;
	while(*envp)
	{
		tmp = add_env_element(head, *envp);
		// split_tmp = ft_split(*envp, '=');
		// tmp = ft_env_new(split_tmp[0], split_tmp[1]);
		// if (!tmp)
		// 	return (free_env_lst(head));
		// ft_lstadd_back((t_list **)&head, (t_list *)tmp);
		// ft_envadd_back(&head, tmp);
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