/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:58:32 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/10 20:58:33 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	toUpperCase(unsigned int __attribute__((unused)) i, char *c)
{
	if (*c >= 'a' && *c <= 'z') {
		*c = *c - ('a' - 'A');
	}
}
int	main(void)
{
	char	str[];

	str[] = "Hello";
	printf("Original string: %s\n", str);
	ft_striteri(str, toUpperCase);
	printf("Uppercase string: %s\n", str);
	return (0);
}
*/