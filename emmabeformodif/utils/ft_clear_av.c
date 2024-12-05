#include "../minishell.h"

void	ft_clear_av(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
