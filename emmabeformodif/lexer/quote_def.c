#include "../minishell.h"

char	*quote_def(char *str)
{
	char	*s;
	int		mode;

	s = str;
	mode = 0;
	while (*s)
	{
		mode = change_mode(mode, *s);
		if (*s == 34 && (mode == 2 || mode == 0))
			*s = DEF_DOUBEL_Q;
		else if (*s == 39 && (mode == 1 || mode == 0))
			*s = DEF_SINGEL_Q;
		s++;
	}
	return (str);
}
