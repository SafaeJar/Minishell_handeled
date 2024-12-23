/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:09:27 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:09:29 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	handle_parse_errors(t_envi_node *new, int parse_result, int *i)
{
	if (parse_result)
	{
		if (parse_result == -1 && *i == 1)
		{
			g_var.exit_status = 512;
			delone_env(new);
			return (2);
		}
		*i += 1;
		delone_env(new);
		return (1);
	}
	return (0);
}

int	check_plus(char *name, char *content)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (name[j])
	{
		if (name[j] == '+')
			count++;
		j++;
	}
	if ((name[j - 1] == '+' && count > 1) || (name[j - 1] == '+'
			&& content[0] == '\0'))
		return (1);
	return (0);
}

int	validate_identifier(char *name, char *content, int len, int err_opt)
{
	int	j;

	j = 0;
	if (print_identifier_error(name, content, err_opt))
		return (-1);
	if (check_plus(name, content))
		return (printf("minishell: export: `%s': not a valid identifier\n",
				name));
	while (name[j])
	{
		if (((name[j] <= 64 && !ft_isdigit(name[j])) || (name[j] >= 91
					&& name[j] <= 96 && name[j] != '_') || name[j] >= 123)
			&& name[len - 1] != '+')
			return (1);
		j++;
	}
	return (0);
}

void	*concatenate_variable(t_envi_node *node)
{
	t_envi_node	*existing_node;
	char		*tmp_name;
	char		*tmp_content;

	tmp_name = ft_strtrim(node->name, "+");
	if (!tmp_name)
		return (printf("minishell: memory was not allocated!!\n"), NULL);
	free(node->name);
	node->name = tmp_name;
	node->len = ft_strlen(node->name);
	existing_node = var_find(g_var.list, node->name);
	if (existing_node && node->content[0] != '\0' && ft_strcmp(node->content,
			"\"\""))
	{
		tmp_content = ft_strjoin(existing_node->content, node->content);
		if (!tmp_content)
			return (printf("minishell: memory was not allocated!!\n"), NULL);
		free(node->content);
		node->content = tmp_content;
	}
	return (NULL);
}

int	parse_export_variable(t_envi_node *node, int _op_error)
{
	int	len;
	int	check_parse;

	if (!strcmp(node->name, "\0"))
	{
		printf("export: '': not a valid identifier\n");
		return (0);
	}
	len = ft_strlen(node->name);
	check_parse = validate_identifier(node->name, node->content, len,
			_op_error);
	if (check_parse)
	{
		if (check_parse == -1)
			return (-1);
		g_var.exit_status = 256;
		return (1);
	}
	if (node->name[len - 1] == '+' && node->len != 1)
		concatenate_variable(node);
	return (0);
}
