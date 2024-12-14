/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:16:10 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:20:59 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	av_size(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (*av++)
		i++;
	return (i);
}

t_parser_node	*node_create(t_command **av, t_redirect_node *rdrlist,
		t_token_type tp)
{
	t_parser_node	*node;

	node = malloc(sizeof(t_parser_node));
	if (!node)
		return (NULL);
	node->av = NULL;
	node->redirect_list = NULL;
	if (av)
	{
		node->av = av_creat(av);
		if (!node->av)
			return (NULL);
	}
	node->ac = av_size(node->av);
	node->type = tp;
	if (rdrlist)
		node->redirect_list = rdrlist;
	node->right_child = NULL;
	node->left_child = NULL;
	return (node);
}

void	node_ptr(t_parser_node **node, t_parser_node *left,
		t_parser_node *right)
{
	(*node)->right_child = right;
	(*node)->left_child = left;
}

void	node_clear(t_parser_node *node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node->av && node->av[i])
			free(node->av[i++]);
		free(node->av);
		rdr_clear(&node->redirect_list);
		free(node);
	}
}

void	node_del(t_parser_node **node)
{
	t_parser_node	*tmp;

	tmp = *node;
	if (tmp)
	{
		node_del(&tmp->left_child);
		node_del(&tmp->right_child);
		node_clear(tmp);
	}
}
