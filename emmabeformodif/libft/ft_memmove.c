/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:57:46 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/03 19:39:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (src >= dest)
	{
		ft_memcpy(d, s, n);
	}
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (d);
}
/*
int	main(void) 
{ 
    char str[100] = "Learningisfun"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n ", str); 
      
    memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n ", str); 

    memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n ", str); 
  
    return (0); 
}*/
