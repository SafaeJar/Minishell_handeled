/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:30:50 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/23 10:30:52 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	(*lst) = new;
}

/*
#include <stdio.h>

int main()
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = "Premier";
    node1->next = node2;

    node2->content = "Deuxième";
    node2->next = node3;

    node3->content = "Troisième";
    node3->next = NULL;

    t_list *currentNode = node1;
    while (currentNode)
    {
        printf("Contenu de l'élément : %s\n", (char *)currentNode->content);
        currentNode = currentNode->next;
    }
    t_list *newNode = ft_lstnew("Nouveau premier");


    ft_lstadd_front(&node1, newNode);

    printf("\nAprès l'ajout :\n");

    currentNode = node1;
    while (currentNode)
    {
        printf("Contenu de l'élément : %s\n", (char *)currentNode->content);
        currentNode = currentNode->next;
    }
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

*/