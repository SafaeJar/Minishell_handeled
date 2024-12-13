/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:31 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 01:06:17 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while ((str1[i] && str2[i]) && (str1[i] == str2[i] && i < n - 1))
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

int ft_strcmp(char *s1, char *s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;  // Both strings are NULL, they are equal
    if (s1 == NULL)
        return -1;  // Only s1 is NULL, so s1 is "less than" s2
    if (s2 == NULL)
        return 1;   // Only s2 is NULL, so s1 is "greater than" s2

    while (*s1 && (*s1 == *s2))  // Compare characters while both are not null
    {
        s1++;
        s2++;
    }

    return (*s1 - *s2);  // Return the difference when ch aracters differ
}
