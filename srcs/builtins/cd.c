/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:49:31 by bterral           #+#    #+#             */
/*   Updated: 2022/03/30 11:46:43 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

static void	update_var(t_cmd *cmd, char *str, char *var)
{
	t_env	*env;

	env = NULL;
	if (ft_strcmp(var, "OLDPWD"))
	{
		ft_envdel(cmd, "OLDPWD");
		env = ft_env_new(ft_strdup("OLDPWD"), ft_strdup(str));
		ft_envadd_back(&cmd->head, env);
		printf("OLDPWD\n");
	}
	else if (ft_strcmp(var, "PWD"))
	{
		ft_envdel(cmd, "PWD");
		env = ft_env_new(ft_strdup("PWD"), ft_strdup(str));
		ft_envadd_back(&cmd->head, env);
		printf("PWD\n");
	}
}

static int	free_return1(char *str)
{
	free(str);
	return (1);
}

int	cd(t_cmd *cmd)
{
	char	*str;
	int		i;

	str = getcwd(NULL, 0);
	if (cmd->str[1])
	{
		if (disable_option(cmd->str[1]))
			free_return1(str);
		else if (chdir(cmd->str[1]))
		{
			ft_dprintf(2, "cd : %s: No such file or directory\n", cmd->str[1]);
			free_return1(str);
		}
		else
		{
			update_var(cmd, str, "OLDPWD");
			free(str);
			str = getcwd(NULL, 0);
			update_var(cmd, str, "PWD");
			return (0);
		}
	}
	return (0);
}
