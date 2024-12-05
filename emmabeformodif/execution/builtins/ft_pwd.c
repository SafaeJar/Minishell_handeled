#include "../../minishell.h"

void ft_pwd(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0);//"get current working directory"(pathname),null->dynamically allocate memory,0->auto determine the buffer size
	if (cwd == NULL)
	{
		perror("getcwd");//prints a descriptive error message to the standard error, This string is printed first,followed(: )and the error message corresponding to the value of errno.
		se.exit_status = 1;
	}
	printf("%s\n",cwd);
	free(cwd);
	se.exit_status = 0;
}