/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:38 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 15:32:38 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	get_token(t_lexer *lexer)
{
	
	while (lexer->current_position && (*lexer->current_position == ' ' || *lexer->current_position == '!'
			|| *lexer->current_position == ':'))
		lexer->current_position++;
	if (lexer->current_position[0] == '\0')
		return (t_init(END, 0, NULL));
	if (!ft_strncmp(lexer->current_position, "|", 1) || !ft_strncmp(lexer->current_position, "&", 1))
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
	// Default case: Collect words or variables
	return (word_collect(lexer, 0, 0));
}
