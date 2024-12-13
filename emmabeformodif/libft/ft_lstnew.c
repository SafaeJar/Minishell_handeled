/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:29:33 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/24 22:21:49 by safae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*toadd;

	toadd = (t_list *)malloc(sizeof(t_list));
	if (!toadd)
		return (NULL);
	toadd->content = content;
	toadd->next = NULL;
	return (toadd);
}

/*
#include <stdio.h>

int	main(void) {

	t_list *newElement = ft_lstnew("Hello, World!");


	if (newElement != NULL) {

		printf("Content: %s\n", (char *)newElement->content);

		free(newElement);
	} else {
		printf("Allocation failed.\n");
	}

	return (0);
}

*/