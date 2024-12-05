/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:56:55 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/29 20:07:02 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return ((unsigned char *)s);
}
// #include <stdio.h>
// int main() {
// int arr[2] = {1,2};
//     ft_memset(arr +1,1,);
//         printf("%d",arr[1]);
//     char characters[10];
//     size_t size = sizeof(characters) / sizeof(characters[0]);
//     printf("Avant  :\n");
//         printf("%s ", characters);
//     printf("\n");
//     ft_memset(characters, 'A', sizeof(characters));
//     printf("Après  :\n");
//         printf("%s ", characters);
//         printf("\n");
// }
