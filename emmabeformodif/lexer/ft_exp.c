/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:16:24 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:17:29 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_exp(char *expnd, char **s)
{
	expnd = exit_status(s);
	if (expnd == (char *)-1)
		expnd = exp_var(s);
	return (expnd);
}
