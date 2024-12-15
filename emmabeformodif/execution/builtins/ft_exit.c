/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:53 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:09:55 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	handle_digit(char *str, int i)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			g_var.exit_status = 2;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(char *argv)
{
	int	i;

	if ((!ft_isdigit(argv[0]) && argv[0] != '-' && argv[0] != '+')
		|| ((argv[0] == '-' || argv[0] == '+') && !argv[1]) || (argv[0] == '-'
			&& argv[1] == '-' && argv[2]))
	{
		g_var.exit_status = 2;
		return (1);
	}
	else if (argv[0] == '-' && argv[1] == '-' && !argv[2])
	{
		g_var.exit_status = 0;
		return (0);
	}
	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	return (handle_digit(argv, i));
}

long long	ft_atol(char *str)
{
	long long	number;
	int			sign;
	int			i;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (256 - (number % 256) % 256);
	return (number % 256);
}

void	ft_exit(t_parser_node *node)
{
	printf("exit\n");
	if (node->ac == 1)
		g_var.exit_status = 0;
	else if (node->ac == 2)
	{
		if (check_args(node->av[1]))
			printf("minishell : exit: %s: numeric argument required\n",
				node->av[1]);
		else
			g_var.exit_status = ft_atol(node->av[1]);
	}
	else
	{
		printf("minishell: exit: too many arguments\n");
		g_var.exit_status = 1;
		return ;
	}
	node_del(&node);
	exit(g_var.exit_status);
}
