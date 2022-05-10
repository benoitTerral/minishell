/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:56:34 by bterral           #+#    #+#             */
/*   Updated: 2022/05/10 14:14:43 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	update_shlvl(t_env **head)
{
	t_env	*ptr;
	t_env	*new_shlv;
	int		shlvl;

	ptr = (*head);
	(void)new_shlv;
	shlvl = 0;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "SHLVL"))
		{
			shlvl = ft_atoi(ptr->value);
			if (shlvl)
				shlvl++;
			free(ptr->value);
			ptr->value = ft_itoa(shlvl);
			return (0);
		}
		ptr = ptr->next;
	}
	if (!shlvl)
		ft_envadd_back(head, ft_env_new(ft_strdup("SHLVL"), ft_strdup("1")));
	return (0);
}

int	init_from_bash(char **env, t_env **head)
{
	char	**split;
	t_env	*env_ptr;

	while (*env)
	{
		split = ft_split(*env, '=');
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
		env++;
	}
	return (0);
}

int	shlvl_exists(t_env **head)
{
	t_env	*ptr;

	ptr = (*head);
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "SHLVL"))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	pwd_missing(t_env **head)
{
	t_env	*ptr;

	ptr = (*head);
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "PWD"))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	init_env_var(char **env, t_env **head)
{
	if (init_from_bash(env, head))
	{
		ft_dprintf(2, "Creating environment varibles failed\n");
		exit(1);
	}
	update_shlvl(head);
	if (pwd_missing(head))
		ft_envadd_back(head,
			ft_env_new(ft_strdup("PWD"), getcwd(NULL, PATH_MAX)));
	return (0);
}
