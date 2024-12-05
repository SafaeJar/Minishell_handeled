#include "../../minishell.h"

void	unset_variable(char *argv, int *check)
{
	int i;

	i = 0;
	if(!var_find(se.list,argv))
		return;
	if(ft_isdigit(argv[0]))
	{
		se.exit_status = 256; // Set exit status for invalid identifier
		*check = 1;
		printf("unset: %s: not a parameter name\n",argv);
		return;
	}
	while(argv[i] && *check == 0)
	{
		if((argv[i] <= 64 && !ft_isdigit(argv[i])) || (argv[i] >= 91
				&& argv[i] <= 96 && argv[i] != '_') || argv[i] >= 123)
		{
			se.exit_status = 256; // Set exit status for invalid identifier
			*check = 1;
			printf("unset: %s: not a parameter name\n",argv);
			return;
		}
		i++;
	}

}

void	ft_unset(t_parser_node *node)
{
	int	check;
	int a;

	a = 1;
	check = 0;
	if(node->ac > 1)
	{
		if(node->av[1][0] == '-')
		{
			se.exit_status = 512; // Set exit status for invalid option
			printf("unset: %s: invalid option\n", node->av[1]);
            printf("unset: usage: unset [name ...]\n");
			return;
		}
		while(node->av[a])
		{
			unset_variable(node->av[a],&check);
			if(check == 0 && var_find(se.list,node->av[a]))
				ft_list_remove_if(&se.list,node->av[a]);
			a++;
		}
		se.exit_status = 0;
	}
	se.exit_status = 1;
	printf("unset: not enough arguments\n");
}
