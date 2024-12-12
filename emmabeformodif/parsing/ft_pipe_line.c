/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:34 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:57:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// t_parser_node *ft_pipe_line(t_lexer *lexer) {
//     t_parser_node *cmd = collect_command(lexer);

//     if (!cmd)
//         return NULL;

//     t_token token = get_next_token(lexer);
//     if (token.type == PIPE) {
//         t_parser_node *pipe = node_create(NULL, NULL, PIPE);
//         pipe->left_child = cmd;
//         pipe->right_child = ft_pipe_line(lexer);

//         if (!pipe->right_child) {
//             printf("minishell: syntax error near unexpected token `|`\n");
//             node_del(&pipe);
//             return NULL;
//         }
//         return pipe;
//     }
//     return cmd;
// }

t_parser_node	*ft_pipe_line(t_lexer *lexer)
{
	t_parser_node	*cmd;
	t_parser_node	*pipe;
	void			*ptr;

	ptr = (void *)-1;
	cmd = collect_command(lexer);
	
	if (cmd && cmd != ptr)
	{
		pipe = check_pipe(lexer);
		if (pipe == ptr)
			return (cmd);
		if (pipe)
			pipe->left_child = cmd;

		else
			node_del(&cmd);
		return (pipe);
	}
	return (cmd);
}
