/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:02 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 19:05:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_list(void)
{
	t_envi_node	*head;

	head = g_var.list;
	while (head)
	{
		delone_env(head);
		head = head->next;
	}
}

const char	*get_wd(char *path)
{
	char	*working_directory;
	char	*cwd;

	cwd = NULL;
	if (path)
	{
		working_directory = ft_strrchr(path, '/');
		working_directory = ft_strjoin("\e[0;35m➜", working_directory);
		cwd = ft_strjoin(working_directory, "\e[0m\e[0;35m => \e[0m ");
		free(path);
		free(working_directory);
	}
	else
		cwd = ft_strdup("\e[0;35m!!➜/N.A.D => \e[0m ");
	return (cwd);
}
