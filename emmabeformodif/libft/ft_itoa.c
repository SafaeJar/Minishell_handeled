/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:58:11 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/22 22:34:43 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n = -n;
		count++;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				x;
	unsigned int	t;
	char			*res;

	x = count(n);
	res = (char *)malloc(sizeof(char) * (x + 1));
	if (!res)
		return (NULL);
	res[x--] = '\0';
	if (n == 0)
		res[x] = '0';
	if (n < 0)
	{
		t = -n;
		res[0] = '-';
	}
	else
		t = n;
	while (t)
	{
		res[x] = t % 10 + 48;
		t = t / 10;
		x--;
	}
	return (res);
}
/*

#include <stdio.h>

int	main(void){
  int x=-1243;
  char *res=ft_itoa(x);
  printf("%s",res);
}
*/
