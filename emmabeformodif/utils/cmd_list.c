/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:55 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:44:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*ft_new_cmd(char *content, t_file_node **list)
{
	t_command	*s;

	s = (t_command *)malloc(sizeof(t_command));
	if (!s)
		return (NULL);
	s->word = content;
	s->files = NULL;
	s->next = NULL;
	if (list)
		s->files = *list;
	return (s);
}

void	cmd_addback(t_command **lst, t_command *new)
{
	t_command	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = cmd_lstlast(*lst);
	p->next = new;
}

t_command	*cmd_lstlast(t_command *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}

int	cmd_size(t_command *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->files)
		{
			i += wc_size(lst->files);
			lst = lst->next;
		}
		else
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

void	cmd_clear(t_command **lst)
{
	t_command	*tmp;

	tmp = 0;
	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->files)
		{
			wc_clear(&(*lst)->files);
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
		else
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp->word);
			free(tmp);
		}
	}
}
