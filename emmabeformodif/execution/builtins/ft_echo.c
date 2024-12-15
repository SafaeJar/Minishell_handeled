/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:40 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:09:42 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_echo(t_parser_node *node, int argc)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (argc > i && !ft_check_n(node->av[i]))
	{
		a = 1;
		i++;
	}
	while (argc > i)
	{
		printf("%s", node->av[i]);
		if (argc > i + 1)
			printf(" ");
		i++;
	}
	if (a == 0)
		printf("\n");
	g_var.exit_status = 0;
}
