/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:58 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:10:00 by ichaoub          ###   ########.fr       */
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
