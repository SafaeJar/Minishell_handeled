#include "../../../minishell.h"

int	handle_parse_errors(t_envi_node *new, int parse_result, int *i)
{
	if (parse_result)
	{
		if (parse_result == -1 && *i == 1)
		{
			se.exit_status = 512;
			delone_env(new);
			return (2);
		}
		*i += 1;
		delone_env(new);
		return (1);
	}
	return (0);
}
int	check_plus(char *name, char *content)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while(name[j])
	{
		if(name[j] == '+') // this fct it check if name has + sign
			count++;
		j++;
	}
	if ((name[j - 1] == '+' && count > 1) ||
		(name[j - 1] == '+' && content[0] == '\0'))//this part check if export var+=hello (export var+= or export v+a++r)
			return(1);
	return(0);
}

// int validate_identifier(char *name, char *content, int len, int err_opt) {
//     int j = 0;

//     // Vérifie si le premier caractère est un chiffre
//     if (ft_isdigit(name[j]))
//         return handle_digit_start(name, content);

//     // Vérifie si une option invalide est détectée
//     if (name[j] == '-' && err_opt == 1)
//         return handle_invalid_option(name);

//     // Vérifie une condition externe (par exemple, le "+" dans le nom)
//     if (check_plus(name, content))
//         return printf("minishell: export: `%s': not a valid identifier\n", name);

//     // Vérifie les caractères invalides dans le nom
//     return check_invalid_characters(name, len);
// }


int	validate_identifier(char *name, char *content, int len, int err_opt)
{
	int j;

	j = 0;
	if(ft_isdigit(name[j]) && !*content)
	{
		return(printf("minishell: export: `%s': not a valid identifier\n",
			name));
	}
	else if(ft_isdigit(name[j]))
	//return(printf("export:: command not found\n"));
		return(printf("minishell: export: `%s=%s': not a valid identifier\n",
			name, content));
	if(name[j] == '-' && err_opt == 1)//argv 1
	{
		printf("minishell: export: %s: invalid option \n", name);
		printf("export: usage: export [name[=value]...] or export \n");
		return (-1);
	}
	if(check_plus(name, content))
		return (printf("minishell: export: `%s': not a valid identifier\n",
				name));
	while (name[j])
	{
		if (((name[j] <= 64 && !ft_isdigit(name[j])) || (name[j] >= 91
					&& name[j] <= 96 && name[j] != '_') || name[j] >= 123)
			&& name[len - 1] != '+')
			return(printf("export:: command not found\n"));
			// return (printf("minishell: export: `%s=%s': ", name, content),
			// 	printf("not a valid identifier\n"));
		j++;
	}
	return (0);
}
void	*concatenate_variable(t_envi_node *node)
{
	t_envi_node		*existing_node;
	char		*tmp_name;
	char		*tmp_content;

	tmp_name = ft_strtrim(node->name, "+");
	if (!tmp_name)
		return (printf("minishell: memory was not allocated!!\n"), NULL);
	free(node->name);
	node->name = tmp_name;
	node->len = ft_strlen(node->name);
	existing_node = var_find(se.list, node->name);
	if (existing_node && node->content[0] != '\0' && ft_strcmp(node->content,
			"\"\""))
	{
		tmp_content = ft_strjoin(existing_node->content, node->content);
		if (!tmp_content)
			return (printf("minishell: memory was not allocated!!\n"), NULL);
		free(node->content);
		node->content = tmp_content;
	}
	return (NULL);
}

int	parse_export_variable(t_envi_node *node, int _op_error)
{
	int	len;
	int	check_parse;

	len = ft_strlen(node->name);
	check_parse = validate_identifier(node->name, node->content, len, _op_error);
	if (check_parse)
	{
		if (check_parse == -1)
			return (-1);
		se.exit_status = 256;
		return (1);
	}
	if (node->name[len - 1] == '+' && node->len != 1)
		concatenate_variable(node);
	return (0);
}