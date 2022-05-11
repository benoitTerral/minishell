/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:54 by bterral           #+#    #+#             */
/*   Updated: 2022/05/10 16:24:02 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	print_export(t_data *data)
{
	t_env	*current;

	current = data->head;
	while (current)
	{
		ft_dprintf(1, "declare -x %s", current->name);
		if (current->value)
			ft_dprintf(1, "=\"%s\"", current->value);
		ft_dprintf(1, "\n");
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
			else if (env->value && split[1])
			{
				free(env->value);
				env->value = ft_strdup(split[1]);
			}
			return (1);
		}
		env = env->next;
	}
	return (0);
}

int	check_and_add_var(t_env **head, char *str)
{
	char	**split;
	t_env	*new;

	split = ft_split(str, '=');
	if (is_var_valid(split[0]) == 0)
	{
		ft_dprintf(2, RED "export: %s : not a valid identifier\n" WHITE, str);
		ft_free_split(split);
		return (1);
	}
	if (is_var_modification(head, split) == 0)
	{
		new = add_env_element(head, str);
		ft_free_split(split);
		return (1);
	}
	ft_free_split(split);
	return (0);
}

int	export(t_data *data)
{
	int		i;

	if (data->nbr_arg == 1)
		return (print_export(data));
	else if (data->str[1] && disable_option(data->str[1], "export"))
		return (1);
	else
	{
		i = 1;
		while (i < data->nbr_arg)
		{
			if (check_and_add_var(&data->head, data->str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
