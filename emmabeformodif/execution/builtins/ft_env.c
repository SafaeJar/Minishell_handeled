/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:47 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:09:49 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_check(void)
{
	t_envi_node	*head;

	head = g_var.list;
	while (head)
	{
		if (ft_strcmp(head->name, "_") == 0)
			return ;
		head = head->next;
	}
	add_dernier(&g_var.list, nv_node("/usr/bin/env", "_", ft_strlen("_")));
}

void	ft_env(t_parser_node *node, int argc)
{
	if (argc != 1)
	{
		if (node->av[1][0] == '-')
		{
			printf("env: invalid option -- '%s'\n", node->av[1]);
			printf("try env with no option or argument\n");
			g_var.exit_status = 1;
			return ;
		}
		else
		{
			printf("env: '%s': No such file or directory\n", node->av[1]);
			g_var.exit_status = 127;
		}
	}
	else
	{
		afficher_liste_env();
		ft_check();
		g_var.exit_status = 0;
	}
}
