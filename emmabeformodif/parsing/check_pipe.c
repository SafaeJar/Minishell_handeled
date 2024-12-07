/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:08 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:28 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser_node *check_pipe(t_lexer *lexer) {
    if (lexer->curent_type.type != PIPE)
        return (void *)-1;

    t_parser_node *pipe_line = ft_pipe_line(lexer);
    if (!pipe_line || pipe_line == (void *)-1) {
        ft_putstr_fd("minishell: syntax error near unexpected token `|`\n", 2);
        return NULL;
    }

    t_parser_node *pipe = node_create(NULL, NULL, PIPE);
    if (pipe)
        pipe->right = pipe_line;

    return pipe;
}

// t_parser_node	*check_pipe(t_lexer *lexer)
// {
// 	t_parser_node	*pipe_line;
// 	t_parser_node	*pipe;
// 	void			*ptr;

// 	ptr = (void *)-1;
// 	if (lexer->curent_type.type == PIPE)
// 	{
// 		pipe_line = ft_pipe_line(lexer);
// 		if (!pipe_line || pipe_line == ptr)
// 		{
// 			ft_putstr_fd("minishell: syntax error: unexpected end of file\n",
// 				2);
// 			return (NULL);
// 		}
// 		else
// 		{
// 			pipe = node_create(NULL, NULL, PIPE);
// 			pipe->right = pipe_line;
// 			if (pipe)
// 				return (pipe);
// 		}
// 		return (pipe_line);
// 	}
// 	else
// 		return (ptr);
// }
