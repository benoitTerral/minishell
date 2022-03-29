/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:49:31 by bterral           #+#    #+#             */
/*   Updated: 2022/03/29 14:24:50 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

void	update_var_PWD(t_cmd *cmd, char *str, char *pwd_or_oldpwd)
{
	t_env	*env;

	env = NULL;
	if (ft_strcmp(pwd_or_oldpwd, "OLDPWD"))
	{
		ft_envdel(cmd, "OLDPWD");
		env = ft_env_new(ft_strdup("OLDPWD"), ft_strdup(str));
		ft_envadd_back(&cmd->head, env);
		printf("OLDPWD\n");
	}
	else if (ft_strcmp(pwd_or_oldpwd, "PWD"))
	{
		ft_envdel(cmd, "PWD");
		env = ft_env_new(ft_strdup("PWD"), ft_strdup(str));
		ft_envadd_back(&cmd->head, env);
		printf("PWD\n");
	}
}

int cd(t_cmd *cmd)
{
	char	*str;
	int		i;

	str = getcwd(NULL, 0);
	if (cmd->str[1])
	{
		if (disable_option(cmd->str[1]))
		{
			free(str);
			return (1);
		}
		else if (chdir(cmd->str[1]))
		{
			ft_dprintf(2, "cd : %s: No such file or directory\n", cmd->str[1]);
			free(str);
			return (1);
		}
		else
		{
			update_var_PWD(cmd, str, "OLDPWD");
			free(str);
			str = getcwd(NULL, 0);
			update_var_PWD(cmd, str, "PWD");
			return (0);
		}
	}
	return (0);
}