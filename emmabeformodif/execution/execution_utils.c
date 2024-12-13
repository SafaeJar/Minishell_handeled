/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:11:47 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 14:46:12 by sjarfi           ###   ########.fr       */
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
	if(!path)
		return(0);
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
	head = se.list;
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

void	free_env(char **env, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(env[i]);
		i++;
	}
	if (index == -1)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
	}
	free(env);
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
