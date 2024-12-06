#include "../minishell.h"

void	print_error(t_token token)
{
	if (token.type == TOKEN)
	{
		ft_putstr_fd("minishell: syntax error: unrecognized token ", 2);
		write(2, "'", 1);
		write(2, &token.pos[0], 1);
		write(2, "'\n", 2);
	}
	if (token.type == ERROR)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		write(2, "'", 1);
		write(2, "|", 1);
		write(2, "'\n", 2);
	}
	if (token.type == END_OF_FILE)
		ft_putstr_fd("minishel: syntax error: unexpected end of file\n", 2);
}
void print_error2(int x)
{
	if(x==2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
		write(2, "'", 1);
		write(2, "&", 1);
		write(2, "'\n", 2);
	}
}