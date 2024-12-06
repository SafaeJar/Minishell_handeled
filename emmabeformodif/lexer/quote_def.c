/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:45 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:28 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*quote_def(char *str)
{
	char	*s;
	int		mode;

	s = str;
	mode = 0;
	while (*s)
	{
		mode = change_mode(mode, *s);
		if (*s == 34 && (mode == 2 || mode == 0))
			*s = DEF_DOUBEL_Q;
		else if (*s == 39 && (mode == 1 || mode == 0))
			*s = DEF_SINGEL_Q;
		s++;
	}
	return (str);
}
