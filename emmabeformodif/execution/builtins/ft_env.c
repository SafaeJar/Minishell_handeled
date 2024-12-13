/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:04:22 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 17:14:32 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_check(void)
{
	t_envi_node	*head;

	head = se.list;
	while (head)
	{
		if (ft_strcmp(head->name, "_") == 0)
			return ;
		head = head->next;
	}
	add_dernier(&se.list, nv_node("/usr/bin/env", "_", ft_strlen("_")));
}

void	ft_env(t_parser_node *node, int argc)
{
	if (argc != 1)
	{
		if (node->av[1][0] == '-')
		{
			printf("env: invalid option -- '%s'\n", node->av[1]);
			printf("try env with no option or argument\n");
			se.exit_status = 1;
			return ;
		}
		else
		{
			printf("env: '%s': No such file or directory\n", node->av[1]);
			se.exit_status = 127;
		}
		//printf("hnaya%s",node->av[1]);
	}
	else
	{
		afficher_liste_env();
		ft_check();
		se.exit_status = 0;
	}
}
