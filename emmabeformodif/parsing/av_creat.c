/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_creat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:05 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:44:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**iter_lst(t_command **lst, t_file_node *tmp, t_command *cmd, char **av)
{
	int	i;

	i = 0;
	while (*lst)
	{
		if ((*lst)->files)
		{
			while ((*lst)->files)
			{
				av[i++] = (*lst)->files->file_name;
				tmp = (*lst)->files;
				(*lst)->files = (*lst)->files->next;
				free(tmp);
			}
		}
		else
			av[i++] = remove_q((*lst)->word);
		cmd = *lst;
		*lst = (*lst)->next;
		free(cmd);
	}
	av[i] = 0;
	return (av);
}

char	**av_creat(t_command **lst)
{
	char		**av;
	int			size;
	t_command	*cmd;
	t_file_node	*tmp;

	cmd = NULL;
	tmp = NULL;
	size = cmd_size(*lst);
	av = malloc(sizeof(char *) * (size + 1));
	if (!av)
		return (NULL);
	av = iter_lst(lst, tmp, cmd, av);
	return (av);
}
