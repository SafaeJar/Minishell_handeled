/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:02 by sjarfi            #+#    #+#             */
/*   Updated: 2023/10/31 16:58:05 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	i = 0;
	size_src = ft_strlen(src);
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (size_src);
}

/*
int	main(void){
	char dst[10];
	char *src="my name if safae";
	int  moi = ft_strlcpy(dst,src,0);
	printf("moi : %d \n",moi);
	printf("la destination : %s",dst);
	int x =  ft_strlen(dst);
	printf("la taille de dest apres la copie : %d",x);
}
*/