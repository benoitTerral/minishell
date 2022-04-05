/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:54 by bterral           #+#    #+#             */
/*   Updated: 2022/04/05 14:04:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	print_export(t_cmd *cmd)
{
	t_env	*current;
	
	current = cmd->head;
	while (current)
	{
		printf("declare -x %s", current->name);
		if (current->value)
			printf("=\"%s\"", current->value);
		printf("\n");
		current = current->next;
	}
	return (0);
}

static int	is_var_modification(t_env **head, char **split)
{
	t_env	*env;

	env = (*head);
	while (env)
	{
		if (ft_strcmp(split[0], env->name))
		{
			if (!(env->value) && split[1])
				env->value = ft_strdup(split[1]);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

int check_and_add_var(t_env **head, char *str)
{
	char	**split;
	t_env	*new;

	split = ft_split(str, '=');
	if (is_var_valid(head, split[0]) == 0)
	{
		ft_dprintf(2, "export: %s : not a valid identifier\n", str);
		free(split);
		return (1);
	}
	if (is_var_modification(head, split) == 0)
	{
		new = add_env_element(head, str);
		free(split);
		return (1);
	}
	free(split);
	return (0);
}

int	export(t_cmd *cmd)
{
	int		i;

	if (cmd->nb_of_arguments == 1)
		return (print_export(cmd));
	else if (cmd->str[1] && disable_option(cmd->str[1]))
		return (1);
	else
	{
		i = 1;
		while (i < cmd->nb_of_arguments)
		{
			if (check_and_add_var(&cmd->head, cmd->str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}