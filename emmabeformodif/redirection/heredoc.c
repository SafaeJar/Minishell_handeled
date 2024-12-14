/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:13:09 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:16:57 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_herdoc_file(t_redirect_node *rdrlst)
{
	t_redirect_node	*head;
	t_redirect_node	*herdoc_file;

	head = rdrlst;
	herdoc_file = NULL;
	while (head)
	{
		if (head->type == HEREDOC)
			herdoc_file = head;
		head = head->next;
	}
	return (herdoc_file->file);
}

void	execute_heredoc_cmd(t_parser_node *node, t_out_in_file *file)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	else if (pid == 0)
	{
		dup2(file->input_file, STDIN_FILENO);
		dup2(file->output_file, STDOUT_FILENO);
		run_command(node);
		exit(0);
	}
	waitpid(pid, NULL, 0);
}

void	*herdoc_(t_parser_node *n, t_redirect_node *lst, t_out_in_file *file,
		int v)
{
	t_redirect_node	*head;
	char			*tmp;

	tmp = get_herdoc_file(lst);
	file->input_file = open(tmp, O_RDWR, 0777);
	if (file->input_file == -1 || file->output_file == -1)
		return (printf("minishell: %s\n", strerror(errno)), NULL);
	head = lst;
	while (head)
	{
		if ((head->type == REDIRECT_OUTPUT || head->type == REDIRECT_APPEND)
			&& (file->input_file != -1 && file->output_file != -1))
			rdr_output(n, head, file, 0);
		if (head->type == REDIRECT_INPUT && file->input_file != -1
			&& file->output_file != -1)
			rdr_input(n, head, file, 0);
		head = head->next;
	}
	if (v == 1 && file->input_file != -1 && file->output_file != -1)
		execute_heredoc_cmd(n, file);
	return (NULL);
}
