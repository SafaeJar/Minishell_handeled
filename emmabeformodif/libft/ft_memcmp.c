/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:03 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/22 22:25:42 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (i < count - 1 && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
/*
int	main(void)
{
    char *s1="\0\0jdshgjhbgjh\0\0dkjasgh";
    char *s2="aaaa";
    int x=memcmp(s1,s2,15);
    int y= ft_memcmp(s1,s2,15);
    printf("my function's return (: %d\n",y));
    printf("string.h function's return (: %d\n",x));
}*/