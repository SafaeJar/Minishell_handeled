/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:15 by sjarfi            #+#    #+#             */
/*   Updated: 2023/10/31 17:00:17 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			n = i;
			while (needle[j] != '\0' && haystack[n] == needle[j] && n < len)
			{
				j++;
				n++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
/*

    const char *chaine = "Bonjour, monde !";
    const char *sous_chaine = "monde";
    size_t longueur_max = 15;

    const char *resultat=ft_strnstr(chaine,sous_chaine,16);

    if (resultat != NULL) {
        printf("La sous-chaîne a été trouvée à l'indice : %ld c est : %s\n",
		(resultat - chaine),resultat);
    } else {
        printf("La sous-chaîne n'a pas été trouvée. resultat : %s\n",resultat);
    }

    return (0);
}*/