#include "../minishell.h"

char	*remove_q(char *str)
{
	char	*s;
	int		n;

	s = str;
	n = ft_strlen(s);
	while (*s)
	{
		if (*s == DEF_SINGEL_Q || *s == DEF_DOUBEL_Q)
			ft_memmove(s, s + 1, n);
		else
			s++;
		n--;
	}
	return (str);
}
