/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:05:52 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 17:05:54 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	go_to_newpath(const char *path, char *current_dir)
{
	char	*newpwd;

	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: %s\n", path, strerror(errno));
		se.exit_status = 1;
		return ;
	}
	newpwd = getcwd(NULL, 0);
	if (!newpwd)
	{
		perror("getcwd");
		se.exit_status = 1;
		return ;
	}
	update_env_var(&se.list, "OLDPWD", current_dir);
	update_env_var(&se.list, "PWD", newpwd);
	free(current_dir);
	free(newpwd);
	se.exit_status = 0;
}

void	ft_cd(char *path, int argc)
{
	t_envi_node	*oldpwd;
	char		*current_dir;

	if (argc > 2)
	{
		printf("cd: too many arguments");
		se.exit_status = 1;
		return ;
	}
	oldpwd = var_find(se.list, "OLDPWD");
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		perror("getcwd");
		se.exit_status = 1;
		return ;
	}
	if (argc == 1 || ft_strcmp(path, "~") == 0
		|| ft_strcmp(path, "--") == 0)
		go_to_home(current_dir);
	else if (ft_strcmp(path, "-") == 0)
		go_to_oldpath(oldpwd, current_dir);
	else
		go_to_newpath(path, current_dir);
}
