/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:06 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 23:39:12 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell_vars	g_var;

void	check_sigquit_(void)
{
	if (WIFSIGNALED(g_var.exit_status))
	{
		if (g_var.check_sigint == 0)
			g_var.exit_status = 130 * 256;
		else if (g_var.check_sigquit == 1)
			g_var.exit_status = 131 * 256;
	}
}

void	afficher_liste_env(void)
{
	t_envi_node	*temp;

	temp = g_var.list;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->content);
		temp = temp->next;
	}
}

char	*get_user_input(char *prompt)
{
	prompt = readline("\033[1;95mminishell> \033[0m");
	if (!prompt)
	{
		if (isatty(0))
			ft_putstr_fd("exit\n", 2);
		exit(0);
	}
	add_history(prompt);
	return (prompt);
}

void	main_helper(char *line, t_parser_node *tree)
{
	line = get_user_input(line);
	if (line && *line)
	{
		tree = parse(line);
		if (tree)
		{
			execution(tree);
			node_del(&tree);
		}
	}
	free(line);
}

int	main(int argc, char **argv, char **env)
{
	t_parser_node	*tree;
	char			*line;

	tree = NULL;
	line = NULL;
	if (argc < 2 && !argv[1])
	{
		ft_signal();
		g_var.list = creer_envi(env);
		while (1)
		{
			if (g_var.check_sigint)
			{
				g_var.check_sigint = 0;
				continue ;
			}
			main_helper(line, tree);
		}
		return (0);
	}
	return (1);
}
