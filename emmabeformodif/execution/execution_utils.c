/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:10:20 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:10:26 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_path_content(char **split_content)
{
	int	i;

	i = 0;
	while (split_content[i])
		free(split_content[i++]);
	free(split_content);
}

int	check_path(char *path)
{
	if (!path)
		return (0);
	return (path[0] == '/' || (path[0] == '.' && path[1] == '/'));
}

char	**copy_env(int size, int index)
{
	char		**env;
	t_envi_node	*head;
	char		*name_eq;

	env = malloc((size + 1) * sizeof(char *));
	if (!env)
		return (perror("minishell malloc"), NULL);
	head = g_var.list;
	while (head && index < size)
	{
		name_eq = ft_strjoin(head->name, "=");
		env[index] = ft_strjoin(name_eq, head->content);
		free(name_eq);
		head = head->next;
		index++;
	}
	env[index] = NULL;
	return (env);
}

void	copy_argv_for_execve(char **root_argv, char **args, char *first_arg)
{
	int	j;

	j = 1;
	args[0] = first_arg;
	while (root_argv[j])
	{
		args[j] = root_argv[j];
		j++;
	}
	args[j] = NULL;
}
