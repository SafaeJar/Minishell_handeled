/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:16 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/13 18:21:36 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;

	x = ft_strlen(s);
	while (x)
	{
		if (s[x] == (unsigned char)c)
			return ((char *)s + x);
		x--;
	}
	if (s[x] == (unsigned char)c)
		return ((char *)s + x);
	return (NULL);
}

/*
int	main(void)
{
char	*string = "hello les ";
char c= 'l';
char *res= ft_strrchr(string,c);
char *res2= strrchr(string,c);
printf("My function's string : %s indice : %ld \n",res,(res-string));
printf("String.h's function's string : %s indice : %ld",res2,(res2-string));
}*/