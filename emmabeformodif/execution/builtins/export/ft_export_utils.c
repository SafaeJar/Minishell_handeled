#include "../../../minishell.h"

// t_envi_node	*find_max_variable(void)
// {
// 	t_envi_node	*head;
// 	t_envi_node	max_var;

// 	max_var.name = "";
// 	max_var.content = "";
// 	max_var.len = 0;
// 	head = se.list;
// 	while (head)
// 	{
// 		if (ft_strcmp(head->name, max_var.name) >= 0)
// 		{
// 			max_var.name = head->name;
// 			max_var.content = head->content;
// 		}
// 		head = head->next;
// 	}
// 	return (max_var);
// }

t_envi_node *find_max_variable(void)
{
    t_envi_node *head = se.list;
    t_envi_node *max_var = NULL;

    while (head)
    {
        if (!max_var || ft_strcmp(head->name, max_var->name) > 0)
            max_var = head;
        head = head->next;
    }
    return max_var;
}
t_envi_node *find_min_variable()
{
    t_envi_node *tmp = se.list;
    t_envi_node *min_var = NULL;

    while (tmp)
    {
        if ((!min_var || ft_strcmp(tmp->name, min_var->name) < 0) && tmp->len != -1)
            min_var = tmp;
        tmp = tmp->next;
    }
    if (min_var)
        min_var->len = -1;
    return min_var;
}
// t_envi_node	*find_min_variable(t_envi_node min_var)
// {
// 	t_envi_node		*tmp;
// 	int			*tmp_len;

// 	tmp_len = NULL;
// 	tmp = se.list;
// 	while (tmp)
// 	{
// 		if (ft_strcmp(tmp->name, min_var.name) <= 0 && tmp->len != -1)
// 		{
// 			min_var = *tmp;
// 			tmp_len = &tmp->len;
// 		}
// 		tmp = tmp->next;
// 	}
// 	*tmp_len = -1;
// 	return (min_var);
// }
t_envi_node	*create_new_node(char *variable_content)
{
	int		index;
	int		len;
	int		name_len;
	char	*content;

	index = 0;
	len = ft_strlen(variable_content);
	name_len = len;
	while (variable_content[index] != '=' && variable_content[index])
		index++;
	if (variable_content[index] == '\0')
		content = ft_strdup("");
	else if (variable_content[index + 1] == '\0')
	{
		content = ft_strdup("\"\"");
		name_len = len - 1;
	}
	else
	{
		content = ft_strdup(&variable_content[index] + 1);
		name_len = len - ft_strlen(&variable_content[index]);
	}
	if (!content)
		return (NULL);
	return (nv_node(content, ft_substr(variable_content, 0, name_len), name_len));
}
int	remove_variable_if_path_empty(t_envi_node *var_node, int *index)
{
	if (!ft_strcmp(var_node->name, "PATH") && var_node->content[0] == '\0')
	{
		*index += 1;
		delone_env(var_node);
		return (1);
	}
	else
		ft_list_remove_if(&se.list, var_node->name);
	return (0);
}
