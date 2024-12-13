/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:47 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 01:08:01 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;  // Convert uppercase letter to lowercase by adding 32
	return (c);
}

void	str_lower(char *str)
{
	int i;

	// Check for NULL input
	if (str == NULL)
		return;

	i = 0;
	while (str[i])  // Iterate through the string until the null terminator
	{
		str[i] = ft_tolower(str[i]);  // Convert each character to lowercase
		i++;
	}
}
