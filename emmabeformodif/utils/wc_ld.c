/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:04 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:18:05 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_wc_node	*lstlast_dir(t_wc_node *lst)
{
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
		lst = lst->next;
	return (lst);
}

void	lstadd_back_dir(t_wc_node **lst, t_wc_node *new_ld)
{
	t_wc_node	*p;

	if (!*lst)
	{
		*lst = new_ld;
		return ;
	}
	p = lstlast_dir(*lst);
	p->next = new_ld;
}

t_wc_node	*lstnew_dir(char *content, int len)
{
	t_wc_node	*s;

	s = (t_wc_node *)malloc(sizeof(t_wc_node));
	if (s == NULL)
		return (NULL);
	s->d_name = content;
	s->len = len;
	s->next = NULL;
	return (s);
}

int	wc_size(t_wc_node *lst)
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

void	wc_clear(t_wc_node **lst)
{
	t_wc_node	*tmp;

	tmp = 0;
	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free((tmp)->d_name);
		free(tmp);
	}
}
