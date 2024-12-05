#include "../minishell.h"

void	free_path_content(char **split_content)
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

// int	check_path(char *path)
// {
// 	int	i;

// 	i = 0;
// 	while (path[i])
// 	{
// 		if (path[i] == '/')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
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


// char	**copy_env(int size, int index)
// {
// 	t_envi_node	*head;
// 	char		*temp;
// 	char		**env;

// 	env = (char **)malloc((size + 1) * sizeof(char *));
// 	if (!env)
// 		return (printf("minishell: memory was not allocated!!\n"), NULL);
// 	head = se.list;
// 	while (head && index < size)
// 	{
// 		temp = ft_strjoin(head->name, "=");
// 		if (!temp)
// 			return (printf("minishell: memory was not allocated!!\n"),
// 				free_env(env, index), NULL);
// 		env[index] = ft_strjoin(temp, head->content);
// 		if (!env[index])
// 			return (printf("minishell: memory was not allocated!!\n"),
// 				free_env(env, index), free(temp), NULL);
// 		free(temp);
// 		head = head->next;
// 		index++;
// 	}
// 	env[index] = NULL;
// 	return (env);
// }

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
