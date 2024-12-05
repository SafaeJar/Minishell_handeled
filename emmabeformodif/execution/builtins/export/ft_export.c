#include "../../../minishell.h"

void	add_variables_to_env(char **argv, int index)
{
	t_envi_node	*new;
	int		check_parse;
	int		check;

	se.exit_status = 0;
	while (argv[index++])
	{
		if (argv[index][0] == ';' || argv[index][0] == '#')
			break ;
		new = create_new_node(argv[index]);
		if (!new)
			return ;
		check_parse = parse_export_variable(new, index);
		check = handle_parse_errors(new, check_parse, &index);
		if (check == 2)
			break ;
		else if (check == 1)
			continue ;
		if (var_find(se.list, new->name))
		{
			if (remove_variable_if_path_empty(new, &index))
				continue ;
		}
		add_dernier(&se.list, new);
	}
}
void	intialise_len(void)
{
	t_envi_node	*head;

	head = se.list;
	while (head)
	{
		head->len = ft_strlen(head->name);
		head = head->next;
	}
}

void	print_sorted_env(void)
{
	t_envi_node	*min_var;
	t_envi_node	*tmp;
	t_envi_node	*max_var;

	max_var = find_max_variable();
	tmp = se.list;
	while (tmp)
	{
		min_var = find_min_variable(*max_var);
		if (min_var->content[0] == '\0')
			printf("declare -x %s\n", min_var->name);
		else if (min_var->content[0] == '\"')
			printf("declare -x %s=%s\n", min_var->name, min_var->content);
		else
			printf("declare a-x %s=\"%s\"\n", min_var->name, min_var->content);
		tmp = tmp->next;
	}
	intialise_len();
}

void	ft_export(char **argv,int argc)
{
	if (argc == 1 || (argc == 2 && (argv[1][0] == '#'
			|| argv[1][0] == ';')))
	{
		print_sorted_env();
		se.exit_status = 0;
	}
	else
		add_variables_to_env(argv, 1);
}
