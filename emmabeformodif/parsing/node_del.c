/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:37 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:38 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	node_clear(t_parser_node *node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node->av && node->av[i])
			free(node->av[i++]);
		free(node->av);
		rdr_clear(&node->rdrlst);
		free(node);
	}
}

void	node_del(t_parser_node **node)
{
	t_parser_node	*tmp;

	tmp = *node;
	if (tmp)
	{
		node_del(&tmp->left);
		node_del(&tmp->right);
		node_clear(tmp);
	}
}
