#include "minishell.h"

void	df_sigint(int sig)
{
	(void)sig;
	se.exit_status = 130;
	se.check_sigint = 1;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	heredoc_sigint(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 1);
	se.exit_status = 130;
	se.check_sigint = 1;
	rl_on_new_line();
	rl_replace_line("", 1);
	exit(se.exit_status);
	rl_redisplay();
}

void	child_sigint(int sig)
{
	(void)sig;
	se.exit_status = 130;
	se.check_sigint = 1;
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

/*
SIG_DEFAULT: The default signal handling state. The shell behaves normally (e.g., Ctrl+C interrupts the current command).
SIG_HEREDOC: Used when the shell is in heredoc mode, where SIGINT should interrupt the heredoc input process.
SIG_CHILD: Used when the shell has created a child process, and signals should be forwarded to the child.
SIG_PARENT: Used when the shell is managing child processes and signals like SIGINT or SIGQUIT should be ignored to avoid accidentally quitting the shell.
*/


// sigint Interrupt/terminate the process witout generatuin a core dumped ()
//core dump (is a file that contains a detailed snapshot of a program's memory at the time it crashed or terminated unexpectedly)
//siquit not only terminate the process but also generate a core dump ,making is useful for debugging