#include "../minishell.h"

void	*handle_content_allocation_error(void)
{
	printf("minishell: memory allocation failed for content!\n");
	return (NULL);
}

void	*handle_name_allocation_error(void *content)
{
	printf("minishell: memory allocation failed for name!\n");
	free(content);
	return (NULL);
}
