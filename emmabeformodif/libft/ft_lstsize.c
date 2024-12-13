/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:31:07 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/23 10:31:09 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node1->content = "Premier";
	node1->next = node2;
	node2->content = "Deuxième";
	node2->next = node3;
	node3->content = "Troisième";
	node3->next = NULL;
	printf("le size est :%d\n",ft_lstsize(node1));
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/