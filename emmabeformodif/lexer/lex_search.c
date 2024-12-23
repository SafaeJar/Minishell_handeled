/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:42 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:03:09 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	expand_all(t_lexer *lexer, int var, int len)
{
	t_token	token;

	if (var == 1)
	{
		token = lex_var(*lexer, len);
		if (token.type == VARIABLE)
		{
			token.len = len;
			return (token);
		}
	}
	return (t_init(WORD, len, lexer->current_position));
}

t_token	word_collect(t_lexer *lexer, int var, int len)
{
	int		mode;
	char	*s;

	mode = 0;
	s = lexer->current_position;
	while (s[len] != '\0' && (mode != 0 || !ft_strchr(" \t\n|&()<>", s[len])))
	{
		mode = change_mode2(mode, s[len]);
		if (s[len] == '$' && mode != 1)
			var = 1;
		if (s[len] == '\\' && s[len + 1])
			len++;
		len++;
	}
	if (mode != 0 && s[len] == '\0')
	{
		ft_putstr_fd("minishell: syntax error: unmatched quotes\n", 2);
		return (t_init(ERROR, 0, NULL));
	}
	if (var)
		return (expand_all(lexer, var, len));
	return (t_init(WORD, len, lexer->current_position));
}
