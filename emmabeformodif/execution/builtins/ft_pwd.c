/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:05:56 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 19:41:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*cwd;
	char	buffer[4096];

	cwd = getcwd(buffer, 4096);
	if (cwd == NULL)
		printf("%s\n", buffer);
	else
		printf("%s\n", cwd);
	g_var.exit_status = 0;
}
