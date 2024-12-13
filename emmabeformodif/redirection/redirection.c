/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:53 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:57:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirection(t_parser_node *node)
{
	t_out_in_file	in_out_file;

	in_out_file.output_file = 1;
	in_out_file.input_file = 0;
	if (node->redirect_list->type == HEREDOC)
		herdoc_(node, node->redirect_list, &in_out_file, 1);
	else if (node->redirect_list->type == REDIRECT_OUTPUT
		|| node->redirect_list->type == REDIRECT_APPEND)
		rdr_output(node, node->redirect_list, &in_out_file, 1);
	else if (node->redirect_list->type == REDIRECT_INPUT)
		rdr_input(node, node->redirect_list, &in_out_file, 1);
}
