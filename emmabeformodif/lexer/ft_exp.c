#include "../minishell.h"

char	*ft_exp(char *expnd, char **s)
{
	expnd = exit_status(s);
	if (expnd == (char *)-1)
		expnd = exp_var(s);
	return (expnd);
}
