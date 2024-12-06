/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:36 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:37 by sjarfi           ###   ########.fr       */
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

t_parser_node	*node_create(t_cmd **av, t_redirect_node *rdrlist, t_token_type tp)
{
	t_parser_node	*node;

	node = malloc(sizeof(t_parser_node));
	if (!node)
		return (NULL);
	node->av = NULL;
	node->rdrlst = NULL;
	if (av)
	{
		node->av = av_creat(av);
		if (!node->av)
			return (NULL);
	}
	node->ac = av_size(node->av);
	node->type = tp;
	if (rdrlist)
		node->rdrlst = rdrlist;
	node->right = NULL;
	node->left = NULL;
	return (node);
}

void	node_ptr(t_parser_node **node, t_parser_node *left,
		t_parser_node *right)
{
	(*node)->right = right;
	(*node)->left = left;
}
