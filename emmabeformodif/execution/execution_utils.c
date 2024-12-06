#include "../minishell.h"

void	clear_path_content(char **split_content)
{
	int	i;

	i = 0;
	while (split_content[i])
		free(split_content[i++]);
	free(split_content);
}
int check_path(char *path) {
    return (path[0] == '/' || (path[0] == '.' && path[1] == '/'));
}


char **copy_env(int size, int index) {
    char **env = malloc((size + 1) * sizeof(char *));
    if (!env)
        return perror("minishell malloc"), NULL;

    t_envi_node *head = se.list;
    while (head && index < size) {
        char *name_eq = ft_strjoin(head->name, "="); // Join name and "="
        env[index] = ft_strjoin(name_eq, head->content); // Join result with content
        free(name_eq); // Free intermediate allocation
        head = head->next;
        index++;
    }
    env[index] = NULL;
    return env;
}


void	free_env(char **env, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(env[i]);
		i++;
	}
	if (index == -1)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
	}
	free(env);
}

void	copy_argv_for_execve(char **root_argv, char **args, char *first_arg)
{
	int	j;

	j = 1;
	args[0] = first_arg;
	while (root_argv[j])
	{
		args[j] = root_argv[j];
		j++;
	}
	args[j] = NULL;
}
