/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:40 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/12 23:38:41 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser_node	*parse(char *input)
{
	t_parser_node	*ast;
	t_lexer			*lexer;

	lexer = lex_init(quote_def(input));
	ast = parse_input(lexer);
	if (!ast || ast == (void *)-1)
	{
		se.exit_status = 258 * 256;
		free(lexer);
		return (NULL);
	}
	free(lexer);
	return (ast);
}
