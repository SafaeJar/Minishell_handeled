/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:05:56 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 23:56:47 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char		*current_dir;
	t_envi_node	*pwd_var;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		pwd_var = var_find(g_var.list, "PWD");
		if (pwd_var && pwd_var->content)
			printf("%s\n", pwd_var->content);
		else
			printf("pwd: error retrieving current directory: %s\n",
				strerror(errno));
		g_var.exit_status = 1;
	}
	else
	{
		printf("%s\n", current_dir);
		free(current_dir);
		g_var.exit_status = 0;
	}
}
