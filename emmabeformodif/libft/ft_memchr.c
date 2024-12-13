/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:48 by sjarfi            #+#    #+#             */
/*   Updated: 2023/10/31 16:59:50 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*str;
	unsigned char	x;

	x = (unsigned char)c;
	str = (unsigned char *)buf;
	while (count > 0)
	{
		if (*str == x)
			return (str);
		str++;
		count--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void){
char *str1="hello sophie ";
char	*res1 = memchr(str1,'s',3);
printf("string.h s function : %s\n",res1);
char *res2= ft_memchr(str1,'s',3);

printf("my function : %s",res2);


}*/
