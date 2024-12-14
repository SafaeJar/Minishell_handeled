/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:14:04 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:15:52 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
