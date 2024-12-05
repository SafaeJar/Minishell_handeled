/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:57:18 by sjarfi            #+#    #+#             */
/*   Updated: 2023/10/31 16:57:20 by sjarfi           ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*
int	main(void) {
    char chaine[10] = "Bonjour";
    printf("Avant bzero: %s\n", chaine);
    ft_bzero(chaine, 2);
    printf("Après bzero: %s\n", chaine);

    return (0);
}
*/
