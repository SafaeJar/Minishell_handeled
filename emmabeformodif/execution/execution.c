/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:10:26 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 18:10:26 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_command(t_parser_node *node)
{
	char	*cmd;

	cmd = ft_strdup(node->av[0]);
	str_lower(cmd);
	if (!ft_strcmp(cmd, "cd"))
		ft_cd(node->av[1], node->ac);
	else if (!ft_strcmp(cmd, "export"))
		ft_export(node);
	else if (!ft_strcmp(cmd, "echo"))
		ft_echo(node, node->ac);
	else if (!ft_strcmp(cmd, "env"))
		ft_env(node, node->ac);
	else if (!ft_strcmp(cmd, "exit"))
		ft_exit(node);
	else if (!ft_strcmp(cmd, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd, "unset"))
		ft_unset(node);
	else
		launch_executable(node, env_listsize(se.list));
	free(cmd);
}

void	ft_pipe(t_parser_node *node)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == 0)
		execute_left_cmd(fd, node->left);
	pid = fork();
	if (pid == 0)
		execute_right_cmd(fd, node->right);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &se.exit_status, 0);
	waitpid(-1, &se.exit_status, 0);
}

void	execute_left_cmd(int *fd, t_parser_node *left)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execution(left);
	exit(127);
}

void	execute_right_cmd(int *fd, t_parser_node *right)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execution(right);
	exit(0);
}

void	execution(t_parser_node *node)
{
	if (node == NULL)
		return ;
	if (node->type == PIPE)
		ft_pipe(node);
	else if (node->type == COMMAND)
	{
		if (node->rdrlst)
			redirection(node);
		else
			run_command(node);
	}
}
