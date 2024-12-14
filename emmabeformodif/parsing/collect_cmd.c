/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:11:50 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:15:38 by sjarfi           ###   ########.fr       */
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

void	heredoc_handler_helper(char *f)
{
	ft_putstr_fd("minishel: ", 2);
	ft_putstr_fd(f, 2);
	ft_putstr_fd(": ", 2);
	printf("minishell: %s:\n", strerror(errno));
}

void	collect_rdr_helper(t_token token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token", 2);
	if (token.position && token.len > 0)
	{
		write(2, "'", 1);
		ft_putnstr(token.position, token.len, 2);
		write(2, "'\n", 2);
	}
	else
	{
		ft_putstr_fd("`newline'\n", 2);
	}
}
