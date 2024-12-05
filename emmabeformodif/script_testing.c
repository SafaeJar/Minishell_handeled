#include "minishell.h"

// int	access_args(char **argv, int argc)
// {
// 	if (argc > 1)
// 	{
// 		if (access(argv[1], F_OK) == -1)
// 		{
// 			printf("minishell: %s: %s\n", argv[1], strerror(errno));
// 			se.exit_status = errno;
// 		}
// 	}
// 	else
// 		se.exit_status = EXIT_SUCCESS;
// 	return (se.exit_status =);
// }