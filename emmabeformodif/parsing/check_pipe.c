/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:14:30 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:15:18 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser_node	*check_pipe(t_lexer *lexer)
{
	t_parser_node	*pipe_line;
	t_parser_node	*pipe;

	if (lexer->current_token.type != PIPE)
		return ((void *)-1);
	pipe_line = ft_pipe_line(lexer);
	if (!pipe_line || pipe_line == (void *)-1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|`\n", 2);
		return (NULL);
	}
	pipe = node_create(NULL, NULL, PIPE);
	if (pipe)
		pipe->right_child = pipe_line;
	return (pipe);
}
