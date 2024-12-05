#include "../minishell.h"

// t_parser_node *ft_pipe_line(t_lexer *lexer) {
//     t_parser_node *cmd = collect_cmd(lexer);

//     if (!cmd)
//         return NULL;

//     t_token token = get_next_token(lexer);
//     if (token.type == PIPE) {
//         t_parser_node *pipe = node_create(NULL, NULL, PIPE);
//         pipe->left = cmd;
//         pipe->right = ft_pipe_line(lexer);

//         if (!pipe->right) {
//             printf("minishell: syntax error near unexpected token `|`\n");
//             node_del(&pipe);
//             return NULL;
//         }
//         return pipe;
//     }
//     return cmd;
// }

t_parser_node	*ft_pipe_line(t_lexer *lexer)
{
	t_parser_node	*cmd;
	t_parser_node	*pipe;
	void			*ptr;

	ptr = (void *)-1;
	cmd = collect_cmd(lexer);
	if (cmd && cmd != ptr)
	{
		pipe = check_pipe(lexer);
		if (pipe == ptr)
			return (cmd);
		if (pipe)
			pipe->left = cmd;
		else
			node_del(&cmd);
		return (pipe);
	}
	return (cmd);
}
