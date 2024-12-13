/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:08:34 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 19:45:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_variable(char *argv, int *check)
{
	int	i;

	i = 0;
	if (!var_find(g_var.list, argv))
		return ;
	if (ft_isdigit(argv[0]))
	{
		g_var.exit_status = 256;
		*check = 1;
		printf("unset: %s: not a parameter name\n", argv);
		return ;
	}
	while (argv[i] && *check == 0)
	{
		if ((argv[i] <= 64 && !ft_isdigit(argv[i])) || (argv[i] >= 91
				&& argv[i] <= 96 && argv[i] != '_') || argv[i] >= 123)
		{
			g_var.exit_status = 256;
			*check = 1;
			printf("unset: %s: not a parameter name\n", argv);
			return ;
		}
		i++;
	}
}

void	ft_unset(t_parser_node *node, int a)
{
	int	check;

	check = 0;
	if (node->ac > 1)
	{
		if (node->av[1][0] == '-')
		{
			g_var.exit_status = 512;
			printf("unset: %s: invalid option\n", node->av[1]);
			printf("unset: usage: unset [name ...]\n");
		}
		else if (node->ac >= 2)
		{
			while (node->av[a])
			{
				unset_variable(node->av[a], &check);
				if (check == 0 && var_find(g_var.list, node->av[a]))
					ft_list_remove_if(&g_var.list, node->av[a]);
				a++;
			}
		}
		g_var.exit_status = 0;
	}
	g_var.exit_status = 1;
}
