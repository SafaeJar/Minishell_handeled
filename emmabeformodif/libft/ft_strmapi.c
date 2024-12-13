/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:58:22 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/04 00:17:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
char	transform(unsigned int index, char c) {
	if(c>= 'a' && c<= 'z')
	return (char)(c - 32);
	else
	return (char)(c);
}

int	main(void) {
	const char *original = "hello, world!";

	char *result = ft_strmapi(original, &transform);

	if (!result) {
		fprintf(stderr, "Erreur d'allocation de mémoire\n");

	}

	printf("Chaine d'origine : %s\n", original);
	printf("Resultat transforme : %s\n", result);


}
*/
