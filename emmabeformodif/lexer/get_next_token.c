#include "../minishell.h"

t_token	get_next_token(t_lexer *lexer)
{
	t_token	token;
	int		i;

	i = 0;
	lexer->prev_type = lexer->curent_type;
	token = get_token(lexer);
	lexer->str += token.len;
	lexer->curent_type = token;
	while (lexer->str[i] && lexer->str[i] == 32)
		i++;
	lexer->str += i;
	return (token);
}
