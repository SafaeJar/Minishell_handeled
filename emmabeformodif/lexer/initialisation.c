#include "../minishell.h"

t_lexer	*lex_init(char *s)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->input_string = s;
	lexer->str = s;
	lexer->prev_type = t_init(TOKEN_NULL, 0, NULL);
	lexer->curent_type = t_init(TOKEN_NULL, 0, NULL);
	return (lexer);
}

t_token	t_init(t_token_type _tp, int len, char *p)
{
	t_token	tok;

	tok.type = _tp;
	tok.pos = p;
	tok.len = len;
	return (tok);
}

t_token	t_wc_init(t_token_type type, int len, t_wc_node *p, char *pos)
{
	t_token	tok;

	(void)p;
	tok.type = type;
	tok.pos = pos;
	tok.len = len;
	return (tok);
}
