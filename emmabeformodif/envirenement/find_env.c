/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:05:10 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 17:05:11 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_find2(t_envi_node *env, char *s, int len)
{
	t_envi_node	*node;

	if (len == -1)
		len = ft_strlen(s);
	while (env)
	{
		if (len == env->len && !ft_strncmp(env->name, s, len))
		{
			node = env;
			return (node->content);
		}
		env = env->next;
	}
	return (NULL);
}

int	env_find3(t_envi_node *env, char *s)
{
	while (env)
	{
		if (!ft_strcmp(env->content, s))
		{
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	delone_env(t_envi_node *node)
{
	free(node->name);
	free(node->content);
	free(node);
}
