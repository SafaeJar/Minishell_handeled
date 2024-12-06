/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:39 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:40 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser_node	*parse_input(t_lexer *lexer)
{
	t_parser_node	*pipeline;
	t_token			token;
	pipeline = ft_pipe_line(lexer);
	if (!pipeline || pipeline == (void *)-1)
		return (pipeline);
	token = get_next_token(lexer);
	if (token.type != END)
	{
		print_error(token);
		//printf("here");
		node_del(&pipeline);
		return (NULL);
	}
	return (pipeline);
}
