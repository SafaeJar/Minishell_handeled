/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:14:42 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:14:44 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_listsize(t_envi_node *env)
{
	int	a;

	a = 0;
	while (env)
	{
		a++;
		env = env->next;
	}
	return (a);
}

void	delete_env(t_envi_node *node)
{
	free(node->name);
	free(node->content);
	free(node);
}

t_envi_node	*var_find(t_envi_node *env, char *s)
{
	int	len;

	len = ft_strlen(s);
	while (env)
	{
		if (len == env->len && ft_strcmp(env->name, s) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	ft_list_remove_if(t_envi_node **begin_list, void *data_ref)
{
	t_envi_node	*cur;

	if (*begin_list == NULL || begin_list == NULL)
		return ;
	cur = *begin_list;
	if (ft_strcmp(cur->name, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur->name);
		free(cur->content);
		free(cur);
		ft_list_remove_if(begin_list, data_ref);
	}
	else
		ft_list_remove_if(&cur->next, data_ref);
}
