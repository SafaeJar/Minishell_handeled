#include "../minishell.h"
t_parser_node	*collect_cmd(t_lexer *lexer)
{
	t_cmd			*elem;
	t_parser_node	*node;
	t_rdr_node		*rdrlst;
	t_token			token;
	void			*ptr;

	ptr = (void *)-1;
	elem = NULL;
	rdrlst = NULL;
	token = get_token(lexer);
	if (token.type != ERROR && token.type != PIPE && token.type != END
		&& token.type != ENDF)
	{
		if (token.type == VAR)
			free(token.pos);
		elem = cmd_ccomponents(lexer, &rdrlst);
	}
	if ((elem || rdrlst) && rdrlst != ptr)
		node = node_create(&elem, rdrlst, CMD);
	else
	{
		cmd_clear(&elem);
		return (ptr);
	}
	return (node);
}
// t_parser_node *collect_cmd(t_lexer *lexer) {
//     t_cmd *cmd_list = NULL;
//     t_rdr_node *rdrlst = NULL;
//     t_token token;

//     while (1) {
//         token = get_next_token(lexer);
//         if (token.type == END || token.type == PIPE || token.type == ERROR)
//             break;

//         if (token.type == WORD || token.type == VAR)
//             cmd_addback(&cmd_list, ft_new_cmd(ft_substr(token.pos, 0, token.len), NULL));
//         else if (token.type == RD_APP || token.type == RD_IN || token.type == RD_OUT || token.type == HERDOC) {
//             t_rdr_node *tmp = collect_rdr(lexer, rdrlst, token);
//             if (!tmp || tmp == (void *)-1) {
//                 cmd_clear(&cmd_list);
//                 rdr_clear(&rdrlst);
//                 return (void *)-1;
//             }
//             rdr_addback(&rdrlst, tmp);
//         }
//     }

//     if (!cmd_list && !rdrlst)
//         return NULL;

//     return node_create(&cmd_list, rdrlst, CMD);
// }

// t_parser_node	*collect_cmd(t_lexer *lexer)
// {
// 	t_cmd			*elem;
// 	t_parser_node	*node;
// 	t_rdr_node		*rdrlst;
// 	t_token			token;
// 	void			*ptr;

// 	ptr = (void *)-1;
// 	elem = NULL;
// 	rdrlst = NULL;
// 	token = get_token(lexer);
// 	if (token.type != ERROR && token.type != PIPE && token.type != END
// 		&& token.type != ENDF)
// 	{
// 		if (token.type == VAR)
// 			free(token.pos);
// 		elem = cmd_ccomponents(lexer, &rdrlst);
// 	}
// 	if ((elem || rdrlst) && rdrlst != ptr)
// 		node = node_create(&elem, rdrlst, CMD);
// 	else
// 	{
// 		cmd_clear(&elem);
// 		return (ptr);
// 	}
// 	return (node);
// }
