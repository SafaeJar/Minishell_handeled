/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:46 by marvin            #+#    #+#             */
/*   Updated: 2024/12/13 21:13:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser_node	*collect_command(t_lexer *lexer)
{
	t_command		*elem;
	t_parser_node	*node;
	t_redirect_node	*rdrlst;
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
			free(token.position);
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
