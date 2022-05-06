/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:56:34 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 16:23:50 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	update_SHLVL(t_env **head)
{
	t_env	*ptr;
	int		shlvl;

	ptr = (*head);
	shlvl = 0;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "SHLVL"))
		{
			shlvl = ft_atoi(ptr->value);
			if (shlvl)
				shlvl++;
			return (0);
		}
		ptr = ptr->next;
	}
	if (!shlvl)
		ft_envadd_back(head, ft_env_new("SHLVL", "1"));
	return (0);
}

int init_from_bash(char **envp, t_env **head)
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

int	init_env_var(char **envp, t_env **head)
{
	if (envp)
		return (init_from_bash(envp, head));
	else if (head)
		return (update_SHLVL(head));
	return (0);
}