#include "../../minishell.h"

int	check_args(char *argv)
{
	int i;

	if((!ft_isdigit(argv[0]) && argv[0] != '-' && argv[0] != '+') ||
			((argv[0] == '-' || argv[0] == '+') && !argv[1]) || 
			(argv[0] == '-' && argv[1] == '-' && argv[2]))
	{
		se.exit_status = 2;
		return(1);
	}
	else if(argv[0] == '-' && argv[1] == '-' && !argv[2])
	{
		se.exit_status = 0;
		return(0);
	}
	i = (argv[0] == '-' || argv[0] == '+') ? 1 : 0;
	while(argv[i])
	{
		if(!ft_isdigit(argv[i]))
		{
			se.exit_status = 2;
			return(1);
		}
		i++;
	}
	return(0);
}
long long	ft_atol(char *str)
{
	long long	number;
	int			sign;
	int			i;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if(sign == -1)
		return(256 - (number % 256) % 256);
	return (number% 256);
}

void	ft_exit(t_parser_node *node)
{
	printf("exit\n");
	if(node->ac == 1)
		se.exit_status = 0;
	else if(node->ac == 2)
	{
		if(check_args(node->av[1]))
			printf("minishell : exit: %s: numeric argument required\n",node->av[1]);
		else
			se.exit_status = ft_atol(node->av[1]);
	}
	else
	{
		printf("minishell: exit: too many arguments\n");
		se.exit_status = 1;
		return;
	}
	node_del(&node);//parsing
	exit(se.exit_status);
}
