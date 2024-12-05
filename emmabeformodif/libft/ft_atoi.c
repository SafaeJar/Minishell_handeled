/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:30 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/13 18:08:08 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ver(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == ' ' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *string)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	res = 0;
	s = 1;
	while (ver(string[i]))
		i++;
	if (string[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (string[i] == '+')
	{
		s = 1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		res = res * 10 + string[i] - 48;
		i++;
	}
	return (res * s);
}

// // #include "ft_atoi.c"
// #include <stdio.h>
// int	main(void){
//     char *s="2147483649";
//     int x=ft_atoi(s);
//     printf("%d",x);
// }