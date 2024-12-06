#include "../minishell.h"

void	handle_rdr(t_lexer *lexer, t_redirect_node **rdr, t_token token,
		t_redirect_node *tmp)
{
	void			*ptr;

	ptr = (void *)-1;
	tmp = collect_rdr(lexer, *rdr, token);
	if (tmp == ptr)
	{
		if (rdr)
			rdr_clear(rdr);
		else
			*rdr = ptr;
	}
	rdr_addback(rdr, tmp);
}

t_cmd	*cmd_ccomponents(t_lexer *lexer, t_redirect_node **rdr)
{
	t_token		token;
	t_cmd		*cmd;
	t_redirect_node	*tmp;
	void		*ptr;

	ptr = (void *)-1;
	cmd = NULL;
	tmp = NULL;
	token = t_init(TOKEN_NULL, 0, NULL);
	while (token.type != END && token.type != ERROR && token.type != PIPE
		&& token.type != TOKEN && token.type != END_OF_FILE && *rdr != ptr)
	{
		token = get_next_token(lexer);
		if (token.type == WORD)
			cmd_addback(&cmd, ft_new_cmd(ft_substr(token.pos, 0, token.len),
					NULL));
		else if (token.type == VARIABLE)
			cmd_addback(&cmd, ft_new_cmd(token.pos, NULL));
		else if (token.type == REDIRECT_APPEND || token.type == REDIRECT_INPUT
			|| token.type == REDIRECT_OUTPUT || token.type == HEREDOC)
			handle_rdr(lexer, rdr, token, tmp);
	}
	return (cmd);
}
