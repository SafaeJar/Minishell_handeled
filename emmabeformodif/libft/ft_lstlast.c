/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:31:19 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/29 20:07:39 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*lastNode;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node1->content = "Premier";
	node1->next = node2;
	node2->content = "Deuxième";
	node2->next = node3;
	node3->content = "Troisième";
	node3->next = NULL;
	lastNode = ft_lstlast(node1);
	if (lastNode)
		printf("Le contenu du dernier élément de la liste est : %s\n",
		(char *)lastNode->content);
	else
		printf("La liste est vide.\n");
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
