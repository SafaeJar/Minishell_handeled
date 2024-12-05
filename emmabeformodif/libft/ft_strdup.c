/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:04 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/13 18:29:43 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	x;
	size_t	i;
	char	*ptr;

	i = 0;
	x = ft_strlen(s1);
	x++;
	ptr = (char *)malloc(x * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*

int	main(void) {
char *s1="zjhfgbrnghdfkjelrg";
char *s=ft_strdup(s1);
char *s2=strdup(s1);
printf("mine :%s\n sys's : %s",s,s2);
}
*/