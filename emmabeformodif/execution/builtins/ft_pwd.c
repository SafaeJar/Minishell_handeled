/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:05:56 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 17:00:59 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	ft_pwd(void)
// {
// 	char	*cwd;

// 	cwd = getcwd(NULL, 0);
// 	if (cwd == NULL)
// 	{
// 		perror("getcwd");
// 		se.exit_status = 1;
// 	}
// 	printf("%s\n", cwd);
// 	free(cwd);
// 	se.exit_status = 0;
// }
void	ft_pwd(void)
{
	char	*cwd;
	char	buffer[4096];

	cwd = getcwd(buffer, 4096);
	if (cwd == NULL)
		printf("%s\n", buffer);
	else
		printf("%s\n", cwd);
	se.exit_status = 0;
}