/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:08:54 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:08:57 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	add_new_env_var(t_envi_node **env_list, char *name, char *content)
{
	t_envi_node	*new_node;

	new_node = (t_envi_node *)malloc(sizeof(t_envi_node));
	new_node->name = ft_strdup(name);
	new_node->content = ft_strdup(content);
	if (!new_node || !(new_node->name) || !(new_node->content))
	{
		printf("minishell: memory allocation failed\n");
		g_var.exit_status = 1;
		free(new_node);
		return ;
	}
	new_node->len = ft_strlen(content);
	new_node->next = *env_list;
	*env_list = new_node;
}

void	update_env_var(t_envi_node **env_list, char *name, char *content)
{
	t_envi_node	*node;

	node = var_find(*env_list, name);
	if (node)
	{
		free(node->content);
		node->content = ft_strdup(content);
	}
	else
		add_new_env_var(env_list, name, content);
}

void	go_to_home(char *current_dir)
{
	t_envi_node	*home_env;

	home_env = var_find(g_var.list, "HOME");
	if (!home_env || !home_env->content)
	{
		printf("minishell: cd: HOME not set\n");
		g_var.exit_status = 1;
		return ;
	}
	if (chdir(home_env->content) != 0)
	{
		perror("cd");
		free(current_dir);
		g_var.exit_status = 1;
		return ;
	}
	update_env_var(&g_var.list, "OLDPWD", current_dir);
	update_env_var(&g_var.list, "PWD", home_env->content);
	free(current_dir);
	g_var.exit_status = 0;
}

void	go_to_oldpath(t_envi_node *oldpwd, char *current_dir)
{
	if (!oldpwd || !oldpwd->content)
	{
		printf("minishell: cd: OLDPWD not set\n");
		g_var.exit_status = 1;
		return ;
	}
	if (chdir(oldpwd->content) != 0)
	{
		perror("cd");
		free(current_dir);
		g_var.exit_status = 1;
		return ;
	}
	printf("%s\n", oldpwd->content);
	update_env_var(&g_var.list, "OLDPWD", current_dir);
	update_env_var(&g_var.list, "PWD", oldpwd->content);
	free(current_dir);
	g_var.exit_status = 0;
}
