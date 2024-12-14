/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:57:58 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 22:09:55 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countw(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

int	countl(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	**mallocfails(char **res, int a)
{
	while (a > 0)
	{
		free(res[a - 1]);
		a--;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		a;
	int		cl;

	if (!s)
		return (NULL);
	cl = countw(s, c);
	a = 0;
	res = (char **)malloc((cl + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (cl == 0 || *s == '\0')
		res[a] = NULL;
	while (*s && cl--)
	{
		while (*s == c)
			s++;
		res[a++] = ft_substr(s, 0, countl(s, c));
		if (!res[a - 1])
			return (mallocfails(res, a - 1));
		s = s + countl(s, c);
	}
	res[a] = NULL;
	return (res);
}
