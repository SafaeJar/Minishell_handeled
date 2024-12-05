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
// t_parser_node *parse(char *input) {
//     t_lexer *lexer = lex_init(quote_def(input));
//     if (!lexer)
//         return NULL;

//     t_parser_node *ast = parse_input(lexer);
//     if (!ast || ast == (void *)-1)
//         se.exit_status = 258 * 256;

//     free(lexer);
//     return ast;
// }

