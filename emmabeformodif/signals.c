/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:10 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 23:44:13 by sjarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		return ;
	}
	if (sig == SIGINT)
	{
		g_var.exit_status = 130;
		g_var.check_sigint = 1;
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	g_var.check_sigquit = 0;
	g_var.check_sigint = 0;
	if (signal(SIGINT, &sig_handler) == SIG_ERR || signal(SIGQUIT,
			SIG_IGN) == SIG_ERR)
		perror("minishell");
}
