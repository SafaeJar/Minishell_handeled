/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:54 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:03:55 by sjarfi           ###   ########.fr       */
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
	se.exit_status = 0;
}
