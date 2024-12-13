/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:51 by sjarfi            #+#    #+#             */
/*   Updated: 2024/10/24 11:26:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*str;

	str = (char *)malloc(size * num);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
/*
#include <stdio.h>

int	main(void) {
	char *str;

	size_t size = 10;
	str = (char *)calloc(size, sizeof(char));

	if (!str) {
		printf("Échec.\n");
		return (1);
	}
	printf("Contenu initial %s\n", str);

	free(str);

	return (0);
}
*/