/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:11 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:16:33 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_mode(int i, char c)
{
	if (c == 39)
	{
		if (i == 2)
			return (i);
		if (i == 1)
			return (0);
		return (1);
	}
	if (c == 34)
	{
		if (i == 1)
			return (i);
		if (i == 2)
			return (0);
		return (2);
	}
	return (i);
}

int	change_mode2(int i, char c)
{
	if (c == DEF_SINGEL_Q)
	{
		if (i == 1)
			return (0);
		if (i == 0)
			return (1);
	}
	if (c == DEF_DOUBEL_Q)
	{
		if (i == 2)
			return (0);
		if (i == 0)
			return (2);
	}
	return (i);
}
