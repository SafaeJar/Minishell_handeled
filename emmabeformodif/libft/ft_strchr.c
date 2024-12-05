/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:02 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/13 18:20:18 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(string);
	while (i <= l)
	{
		if (string[i] == (char)c)
			return ((char *)(string + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
char	*string = "";
char c= 'l';
char *res= ft_strchr(string,c);
char *res2= strchr(string,c);
printf("My function's string : %s indice : %ld \n",res,(res-string));
printf("String.h's function's string : %s indice : %ld",res2,(res2-string));
}*/