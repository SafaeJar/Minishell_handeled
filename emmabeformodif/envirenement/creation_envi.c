#include "../minishell.h"

t_envi_node	*add_env_node(t_envi_node *var, char *s, int j)
{
	t_envi_node	*new;
	char		*name;
	char		*content;

	while (s[j])
	{
		if (s[j] == '=')
		{
			content = ft_substr(s, j + 1, -1);
			if (!content)
				handle_content_allocation_error();
			name = ft_substr(s, 0, j);
			if (!name)
				handle_name_allocation_error(content);
			new = nv_node(content, name, j);
			if (!new)
				return (free(name), free(content), NULL);
			add_dernier(&var, new);
			break ;
		}
		j++;
	}
	return (var);
}

void	_shell_level(t_envi_node **lst)
{
	t_envi_node	*head;
	char		*shlvl;

	head = *lst;
	while (head)
	{
		if (ft_strcmp(head->name, "SHLVL") == 0)
		{
			shlvl = ft_itoa(ft_atoi(head->content) + 1);
			if (!shlvl)
			{
				printf("minishell: memory was not allocated!\n");
				return ;
			}
			free(head->content);
			head->content = shlvl;
			return ;
		}
		head = head->next;
	}
	add_dernier(lst, nv_node(ft_strdup("1"), ft_strdup("SHLVL"), 5));
}

void	_set_pwd(t_envi_node **lst)
{
	t_envi_node	*head;
	char		*cwd;

	head = *lst;
	while (head)
	{
		if (ft_strcmp(head->name, "PWD") == 0)
			return ;
		head = head->next;
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		printf("minishell: échec de l'obtention du répertoire courant.\n");
		return ;
	}
	add_dernier(lst, nv_node(cwd, ft_strdup("PWD"), 3));
}

t_envi_node	*creer_envi(char **env)
{
	t_envi_node	*var;
	int			i;

	i = 0;
	var = NULL;
	while (env[i])
	{
		var = add_env_node(var, env[i], 0);
		if (!var)
			return (NULL);
		i++;
	}
	_set_pwd(&var);
	_shell_level(&var);
	return (var);
}
