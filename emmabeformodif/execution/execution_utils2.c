/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:13:18 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 14:47:26 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_file(char *path, char **argv, char **env, int v)
{
	pid_t	pid;

	if (access(path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("minishell fork");
			return (0);
		}
		else if (pid == 0)
		{
			if (execve(path, argv, env))
			{
				perror("minishell");
				exit(127);
			}
		}
		waitpid(pid, &se.exit_status, 0);
		if (v == 2)
			free(path);
		return (1);
	}
	else if (v == 1)
	{
		printf("minishell: %s: command not found\n", argv[0]);
		se.exit_status = 127 * 256;
	}
	return (0);
}

char	*search_(char **split_content, char **argv, char **args, int index)
{
	char	*tmp_path;
	char	*tmp2_path;

	tmp_path = ft_strjoin("/", argv[0]);
	if (!tmp_path)
		return (printf("minishell: memory was not allocated!!\n"),
			clear_path_content(split_content), NULL);
	tmp2_path = ft_strjoin(split_content[index], tmp_path);
	if (!tmp2_path)
		return (printf("minishell: memory was not allocated!!\n"),
			clear_path_content(split_content), free(tmp_path), NULL);
	free(tmp_path);
	copy_argv_for_execve(argv, args, tmp2_path);
	return (tmp2_path);
}

void	*searsh_in_path(char *path, char **argv, char **env, char **args)
{
	char	**split_content;
	char	*tmp_path;
	int		i;

	split_content = ft_split(path, ':');
	if (!split_content)
		return (NULL);
	i = 0;
	while (split_content[i])
	{
		tmp_path = search_(split_content, argv, args, i);
		if (!tmp_path)
			return (NULL);
		if (execute_file(tmp_path, args, env, 2))
		{
			clear_path_content(split_content);
			return ((void *)1);
		}
		free(tmp_path);
		i++;
	}
	se.exit_status = 127 * 256;
	clear_path_content(split_content);
	return (NULL);
}

void	*launch(t_parser_node *root, char **env)
{
	t_envi_node	*path_node;
	char		**args;

	args = (char **)malloc(sizeof(char *) * (root->ac + 1));
	if (!args)
		return (printf("minishell: memory was not allocated!!\n"), NULL);
	path_node = var_find(se.list, "PATH");
	if (path_node)
	{
		if (!searsh_in_path(path_node->content, root->av, env, args))
			return (free(args), NULL);
	}
	else
	{
		se.exit_status = 127 * 256;
		printf("minishell: %s: No such file or directory\n", root->av[0]);
	}
	free(args);
	return ((void *)1);
}

void	*launch_executable(t_parser_node *root, int size)
{
	char	**env;

	env = copy_env(size, 0);
	if (!env)
		return (NULL);
	if (check_path(root->av[0]))
	{
		if (!execute_file(root->av[0], root->av, env, 1))
		{
			write(2, "minishell: ", 11);
            write(2, root->av[0], strlen(root->av[0]));
            write(2, ": command not found\n", 20);
		}
			//printf("minishell: %s: command not found\n", root->av[0]);
	}
	else
	{
		if (!launch(root, env))
		{
			write(2, "minishell: ", 11);
            write(2, root->av[0], ft_strlen(root->av[0]));
            write(2, ": command not found\n", 20);
		}
			//printf("minishell: %s: command not found\n", root->av[0]);
	}
	free_env(env, size);
	return (NULL);
}
