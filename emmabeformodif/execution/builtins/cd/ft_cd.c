/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:07 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:09:09 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	go_to_newpath(const char *path, char *current_dir)
{
	char	*newpwd;

	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: %s\n", path, strerror(errno));
		g_var.exit_status = 1;
		return ;
	}
	newpwd = getcwd(NULL, 0);
	if (!newpwd)
	{
		perror("getcwd");
		g_var.exit_status = 1;
		return ;
	}
	update_env_var(&g_var.list, "OLDPWD", current_dir);
	update_env_var(&g_var.list, "PWD", newpwd);
	free(current_dir);
	free(newpwd);
	g_var.exit_status = 0;
}

void	ft_cd(char *path, int argc)
{
	char	*current_dir;

	if (argc > 2)
	{
		printf("cd: too many arguments");
		g_var.exit_status = 1;
		return ;
	}
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		perror("getcwd");
		g_var.exit_status = 1;
		return ;
	}
	if (argc == 1 || ft_strcmp(path, "~") == 0 || ft_strcmp(path, "--") == 0)
		go_to_home(current_dir);
	else if (ft_strcmp(path, "-") == 0)
		go_to_oldpath(var_find(g_var.list, "OLDPWD"), current_dir);
	else
		go_to_newpath(path, current_dir);
}
