/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:04 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file_node	*lstlast_dir(t_file_node *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}

void	lstadd_back_dir(t_file_node **lst, t_file_node *new_ld)
{
	t_file_node	*p;

	if (!*lst)
	{
		*lst = new_ld;
		return ;
	}
	p = lstlast_dir(*lst);
	p->next = new_ld;
}

t_file_node	*lstnew_dir(char *content, int len)
{
	t_file_node	*s;

	s = (t_file_node *)malloc(sizeof(t_file_node));
	if (s == NULL)
		return (NULL);
	s->file_name = content;
	s->len = len;
	s->next = NULL;
	return (s);
}

int	wc_size(t_file_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	wc_clear(t_file_node **lst)
{
	t_file_node	*tmp;

	tmp = 0;
	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free((tmp)->file_name);
		free(tmp);
	}
}
