/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:41 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 21:14:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(t_token token)
{
	if (token.type == TOKEN)
	{
		ft_putstr_fd("minishell: syntax error: unrecognized token ", 2);
		write(2, "'", 1);
		write(2, &token.position[0], 1);
		write(2, "'\n", 2);
	}
	if (token.type == ERROR)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		write(2, "'", 1);
		write(2, "|", 1);
		write(2, "'\n", 2);
	}
	if (token.type == END_OF_FILE)
		ft_putstr_fd("minishel: syntax error: unexpected end of file\n", 2);
}

void	print_error2(int x)
{
	if (x == 2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
		write(2, "'", 1);
		write(2, "&", 1);
		write(2, "'\n", 2);
	}
}
