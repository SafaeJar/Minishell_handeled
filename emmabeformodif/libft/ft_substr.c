/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:57:17 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/13 18:18:37 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	x;
	size_t	i;

	if (!s)
		return (NULL);
	x = ft_strlen(s);
	i = 0;
	if (start >= x)
		len = 0;
	if (x - start < len)
		len = x - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len && start < x)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include "ft_substr.c"
#include <stdio.h>

int	main(void)
{
	char	string[30] = "bonjours tous le monde";
	char	*s;

	s = ft_substr(string, 2, 5);
	printf("%s", s);
}
*/