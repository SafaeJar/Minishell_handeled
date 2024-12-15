/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:10:42 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:10:44 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	execute_file(char *path, char **argv, char **env, int v)
{
	if (check_access(path, argv, env, v))
		return (1);
	else if (v == 1)
	{
		printf("minishell: %s: command not found\n", argv[0]);
		g_var.exit_status = 127 * 256;
	}
	return (0);
}
