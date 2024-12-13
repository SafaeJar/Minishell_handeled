/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:51:54 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 00:04:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	print_identifier_error(char *name, char *content, int err_opt)
{
	if (ft_isdigit(name[0]) && !*content)
	{
		return (printf("minishell: export: `%s': not a valid identifier\n",
				name));
	}
	else if (ft_isdigit(name[0]))
		return (printf("minishell: export: `%s=%s': not a valid identifier\n",
				name, content));
	if (name[0] == '-' && err_opt == 1)
	{
		printf("minishell: export: %s: invalid option \n", name);
		printf("export: usage: export [name[=value]...] or export \n");
		return (-1);
	}
	return (0);
}

void	handle_existing_variable(t_envi_node *new, int *index)
{
	if (var_find(g_var.list, new->name))
	{
		if (remove_variable_if_path_empty(new, index))
			return ;
	}
	add_dernier(&g_var.list, new);
}
