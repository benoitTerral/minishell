/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/03/23 16:16:55 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int	is_build_in(t_cmd cmd)
{
	if ((ft_strncmp(cmd.str[0], "echo", 4) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("echo"))
		return (echo(cmd));
	else if ((ft_strncmp(cmd.str[0], "cd", 2) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("cd"))
		return (cd(cmd));
	else if ((ft_strncmp(cmd.str[0], "pwd", 3) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("pwd"))
		return (pwd());
	else if ((ft_strncmp(cmd.str[0], "export", 6) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("export"))
		return (export(cmd));
	else if ((ft_strncmp(cmd.str[0], "unset", 5) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("unset"))
		return (unset(&cmd));
	else if ((ft_strncmp(cmd.str[0], "env", 3) == 0)
		&& ft_strlen(cmd.str[0]) == ft_strlen("env"))
		return (env(cmd));
	return (0);
}

int pwd(void)
{
	char path[PATH_MAX];

	getcwd(path, PATH_MAX);
	printf("%s\n", path);
	return (1);
}

int	echo_argument(t_cmd cmd)
{
	int	i;

	if (cmd.str[1] && ft_strncmp(cmd.str[1], "-n", 2) == 0)
	{
		i = 2;
		while (cmd.str[1][i])
		{
			if (cmd.str[1][i] != 'n')
				return (0);
			i++;
		}
		i = 2;
		while (cmd.str[i])
		{
			printf("%s", cmd.str[i]);
			if (i < (cmd.nb_of_arguments - 1))
				printf(" ");
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo(t_cmd cmd)
{
	int	i;

	if (echo_argument(cmd))
		return (1);
	i = 1;
	while (cmd.str[i])
	{
		printf("%s", cmd.str[i]);
		if (i == (cmd.nb_of_arguments - 1))
			printf("\n");
		else
			printf(" ");
		i++;
	}
	return (1);
}

void	cd_update_OLDPWD(t_cmd cmd)
{
	t_env	*env;
	char	*str;

	env = cmd.head;
	while (env)
	{
		if (!ft_strncmp(env->name, "OLDPWD", ft_strlen("OLDPWD")) &&
			ft_strlen(env->name) == ft_strlen("OLDPWD"))
		{
			printf("name --  %s\n", env->name);
			// free(env->value);
			// env->value = NULL;
			str = getcwd(NULL, 0);
			*(env->value) = *str;
			printf("name --  %s\n", env->value);
			break;
		}
		env = env->next;
	}
}

int cd(t_cmd cmd)
{
	cd_update_OLDPWD(cmd);
	if (cmd.str[1])
	{
		if (chdir(cmd.str[1]))
		{
			write(STDERR_FILENO, "cd : ", 5);
			write(STDERR_FILENO, cmd.str[1], ft_strlen(cmd.str[1]));
			perror(" ");
		}
	}
	printf("After cd: %s\n", getcwd(NULL, 0));
	return (1);
}

int	export(t_cmd cmd)
{
	t_env	*current;
	t_env	*new;
	int		i;

	if (cmd.nb_of_arguments == 1)
	{
		current = cmd.head;
		while (current)
		{
			printf("declare -x %s", current->name);
			if (current->value)
				printf("=\"%s\"", current->value);
			printf("\n");
			current = current->next;
		}
	}
	else
	{
		i = 1;
		while (i < cmd.nb_of_arguments)
		{
			new = add_env_element(cmd.head, cmd.str[i]);
			i++;
		}
	}
	return (0);
}

int	unset(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (!cmd->str[i])
	{
		write(2, "unset: not enough arguments\n" ,
			ft_strlen("unset: not enough arguments\n"));
		return (1);
	}
	while (cmd->str[i])
	{
		printf("cmd->str[i] : %s", cmd->str[i]);
		ft_envdel(cmd, cmd->str[i]);
		i++;
	}
	return (0);
}

int	env(t_cmd cmd)
{
	t_env	*current;

	current = cmd.head;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	// char	**tmp;
	t_env	*print_ptr;

	(void)argc;
	(void)argv;

	// while (*envp)
	// {
	// 	tmp = ft_split(*envp, "=");
	// 	*envp++
	// }
	cmd.str = ft_split_piscine("cd ..", " \r\t");
	cmd.token = 0;
	cmd.nb_of_arguments = ft_size_split("cd ..", " \r\t", 0);
	cmd.head = init_env_var(envp);

	// printf("\n\n\n            ----------       ENVIRONMENT LIST START          --------------          \n\n\n");
	// print_ptr = cmd.head;
	// while (print_ptr)
	// {
	// 	printf("print_ptr.name : %s", print_ptr->name);
	// 	printf("                                                 print_ptr.value : %s\n", print_ptr->value);
	// 	print_ptr = print_ptr->next;
	// }
	// printf("\n\n\n");

	is_build_in(cmd);
	// printf("not handled yet\n");


	cmd.str = ft_split_piscine("export", " \r\t");
	cmd.token = 0;
	cmd.nb_of_arguments = ft_size_split("export", " \r\t", 0);
	cmd.head = init_env_var(envp);

	if (is_build_in(cmd))
		return (0);


	// printf("\n\n\n            ----------       ENVIRONMENT LIST START          --------------          \n\n\n");
	// print_ptr = cmd.head;
	// while (print_ptr)
	// {
	// 	printf("print_ptr.name : %s", print_ptr->name);
	// 	printf("                                                 print_ptr.value : %s\n", print_ptr->value);
	// 	print_ptr = print_ptr->next;
	// }


	return (0);
}
