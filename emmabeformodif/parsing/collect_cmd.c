#include "../minishell.h"
t_parser_node	*collect_cmd(t_lexer *lexer)
{
	t_cmd			*elem;
	t_parser_node	*node;
	t_redirect_node		*rdrlst;
	t_token			token;
	void			*ptr;

	ptr = (void *)-1;
	elem = NULL;
	rdrlst = NULL;
	token = get_token(lexer);
	if (token.type != ERROR && token.type != PIPE && token.type != END
		&& token.type != END_OF_FILE)
	{
		if (token.type == VARIABLE)
			free(token.pos);
		elem = cmd_ccomponents(lexer, &rdrlst);
	}
	if ((elem || rdrlst) && rdrlst != ptr)
		node = node_create(&elem, rdrlst, COMMAND);
	else
	{
		cmd_clear(&elem);
		return (ptr);
	}
	return (node);
}

