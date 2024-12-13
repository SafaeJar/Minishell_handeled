/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:38 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 00:14:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	handle_special_tokens(t_lexer *lexer)
{
	if (!ft_strncmp(lexer->current_position, "|", 1)
		|| !ft_strncmp(lexer->current_position, "&", 1))
	{
		if (!ft_strncmp(lexer->current_position, "&", 1))
		{
			print_error2(2);
			return (t_init(ERROR, 0, NULL));
		}
		if (lexer->prev_token.type == PIPE
			|| lexer->prev_token.type == TOKEN_NULL)
		{
			print_error(t_init(ERROR, 0, NULL));
			return (t_init(ERROR, 0, NULL));
		}
		return (t_init(PIPE, 1, lexer->current_position));
	}
	if (!ft_strncmp(lexer->current_position, "<<", 2))
		return (t_init(HEREDOC, 2, lexer->current_position));
	if (!ft_strncmp(lexer->current_position, ">>", 2))
		return (t_init(REDIRECT_APPEND, 2, lexer->current_position));
	if (!ft_strncmp(lexer->current_position, "<", 1))
		return (t_init(REDIRECT_INPUT, 1, lexer->current_position));
	if (!ft_strncmp(lexer->current_position, ">", 1))
		return (t_init(REDIRECT_OUTPUT, 1, lexer->current_position));
	return (t_init(TOKEN_NULL, 0, NULL));
}

t_token	get_token(t_lexer *lexer)
{
	t_token	token;

	while (lexer->current_position && (*lexer->current_position == ' '
			|| *lexer->current_position == '!'
			|| *lexer->current_position == ':'))
		lexer->current_position++;
	if (lexer->current_position[0] == '\0')
		return (t_init(END, 0, NULL));
	token = handle_special_tokens(lexer);
	if (token.type != TOKEN_NULL)
		return (token);
	return (word_collect(lexer, 0, 0));
}
