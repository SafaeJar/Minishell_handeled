/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:10 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/13 19:05:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	df_sigint(int sig)
{
	(void)sig;
	g_var.exit_status = 130;
	g_var.check_sigint = 1;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	heredoc_sigint(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 1);
	g_var.exit_status = 130;
	g_var.check_sigint = 1;
	rl_on_new_line();
	rl_replace_line("", 1);
	exit(g_var.exit_status);
	rl_redisplay();
}

void	child_sigint(int sig)
{
	(void)sig;
	g_var.exit_status = 130;
	g_var.check_sigint = 1;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	handle_signal(int state)
{
	if (state == SIG_DEFAULT)
	{
		signal(SIGINT, df_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (state == SIG_HEREDOC)
	{
		signal(SIGINT, heredoc_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (state == SIG_CHILD)
	{
		signal(SIGQUIT, child_sigint);
		signal(SIGINT, SIG_DFL);
	}
	else if (state == SIG_PARENT)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
