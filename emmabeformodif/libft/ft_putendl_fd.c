/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:59:09 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/22 22:21:13 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
// #include<fcntl.h>
// #include<stdio.h>
// int main()
// {
// 	int fd;
// 	fd=open("try.txt",O_CREAT | O_RDWR);
// 	ft_putendl_fd("hellooooo",fd);
// 	printf("%d\n",fd);
// }