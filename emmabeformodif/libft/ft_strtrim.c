/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:57:47 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/29 20:06:15 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, (char)*s1) != NULL)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, *(s1 + len - 1)) != 0)
		len--;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res = ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}

// #include<stdio.h>
// int main(){
// 	char *s=NULL;
// 	char *set="";
// 	char *res;
// 	res=ft_strtrim(s,set);
// 	printf("%s",res);
// }
