#include"../minishell.h"

t_envi_node *add_env_node(t_envi_node *var, char *s)
{
    t_envi_node *new;
    char *name;
    char *content;
    int j = 0;

    while (s[j])
    {
        if (s[j] == '=')
        {
            content = ft_substr(s, j + 1, -1);
            if (!content)
                return (printf("minishell: memory allocation failed for content!\n"), NULL);
            name = ft_substr(s, 0, j);
            if (!name)
                return (printf("minishell: memory allocation failed for name!\n"),
                        free(content), NULL);
            new = nv_node(content, name, j);
            if (!new)
                return (free(name), free(content), NULL);
            add_dernier(&var, new);
            break;
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

t_envi_node *creer_envi(char **env)
{
    t_envi_node *var;
    int i;

    i=0;
    var=NULL;
    while(env[i])
    {
        var = add_env_node(var,env[i]);
        if(!var)
            return(NULL);
        i++;
    }
    _set_pwd(&var);
    _shell_level(&var);
    return(var);
}
