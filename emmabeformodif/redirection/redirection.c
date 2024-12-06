#include "../minishell.h"

void	redirection(t_parser_node *node)
{
	t_out_in_file	in_out_file;

	in_out_file.output_file = 1;
	in_out_file.input_file = 0;
	if (node->rdrlst->type == HEREDOC)
		herdoc_(node, node->rdrlst, &in_out_file, 1);
	else if (node->rdrlst->type == REDIRECT_OUTPUT || node->rdrlst->type == REDIRECT_APPEND)
		rdr_output(node, node->rdrlst, &in_out_file, 1);
	else if (node->rdrlst->type == REDIRECT_INPUT)
		rdr_input(node, node->rdrlst, &in_out_file, 1);
}
