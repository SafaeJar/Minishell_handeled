/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:00 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:17:16 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_q(char *str)
{
	char	*s;
	int		n;

	s = str;
	n = ft_strlen(s);
	while (*s)
	{
		if (*s == DEF_SINGEL_Q || *s == DEF_DOUBEL_Q)
			ft_memmove(s, s + 1, n);
		else
			s++;
		n--;
	}
	return (str);
}
