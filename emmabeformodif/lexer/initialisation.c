/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:40 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:05:39 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*lex_init(char *s)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->input_string = s;
	lexer->current_position = s;
	lexer->prev_token = t_init(TOKEN_NULL, 0, NULL);
	lexer->current_token = t_init(TOKEN_NULL, 0, NULL);
	return (lexer);
}

t_token	t_init(t_token_type _tp, int len, char *p)
{
	t_token	tok;

	tok.type = _tp;
	tok.position = p;
	tok.len = len;
	return (tok);
}

t_token	t_wc_init(t_token_type type, int len, t_file_node *p, char *pos)
{
	t_token	tok;

	(void)p;
	tok.type = type;
	tok.position = pos;
	tok.len = len;
	return (tok);
}

char	*ft_exp(char *expnd, char **s)
{
	expnd = exit_status(s);
	if (expnd == (char *)-1)
		expnd = exp_var(s);
	return (expnd);
}
