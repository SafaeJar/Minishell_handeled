/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:34 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/11 17:54:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	get_next_token(t_lexer *lexer)
{
	t_token	token;
	int		i;

	i = 0;
	lexer->prev_token = lexer->current_token;
	token = get_token(lexer);
	lexer->current_position += token.len;
	lexer->current_token = token;
	while (lexer->current_position[i] && lexer->current_position[i] == 32)
		i++;
	lexer->current_position += i;
	return (token);
}
