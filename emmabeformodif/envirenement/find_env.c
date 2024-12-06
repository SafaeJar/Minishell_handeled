#include "../minishell.h"

char	*env_find2(t_envi_node *env, char *s, int len)
{
	t_envi_node	*node;

	if (len == -1)
		len = ft_strlen(s);
	while (env)
	{
		if (len == env->len && !ft_strncmp(env->name, s, len))
		{
			node = env;
			return (node->content);
		}
		env = env->next;
	}
	return (NULL);
}

int	env_find3(t_envi_node *env, char *s)
{
	while (env)
	{
		if (!ft_strcmp(env->content, s))
		{
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	delone_env(t_envi_node *node)
{
	free(node->name);
	free(node->content);
	free(node);
}
