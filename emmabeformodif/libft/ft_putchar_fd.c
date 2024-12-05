/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:58:47 by sjarfi            #+#    #+#             */
/*   Updated: 2023/11/22 22:21:19 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
// #include<fcntl.h>
// #include<stdio.h>
// int main()
// {
// 	int fd;
// 	fd=open("safae.txt",O_CREAT | O_RDWR);
// 	ft_putchar_fd('o',fd);
// 	printf("%d \n",fd);
// }