#include "minishell.h"
t_shell_vars se;

void	check_sigquit_(void)
{
	if (WIFSIGNALED(se.exit_status))
	{
		if (se.check_sigint == 0)
			se.exit_status = 130 * 256;
		else if (se.check_sigquit == 1)
			se.exit_status = 131 * 256;
	}
}
void afficher_liste_env(void)
{
    t_envi_node *temp;

    temp = se.list;
    while (temp)
    {
        printf("%s=%s\n", temp->name ,temp->content);
        temp = temp->next;
    }
}

char *get_user_input(char *prompt)
{
    prompt = readline("\033[1;95m minishell> \033[0m");
    if(!prompt)
    {
        if(isatty(0))//to check whether standard input is coming from a terminal (interactive mode) or from a file or pipe (non-interactive mode)(standard input(0))
            ft_putstr_fd("exit\n", 2);
        exit(0);
    }
    add_history(prompt);
    return(prompt);
}

int main(int argc, char **argv, char **env)
{
    t_parser_node *tree;
    char *line;

    tree = NULL;
	// arg_check = access_args(argv, argc);
	// if (arg_check != EXIT_SUCCESS)
    //     return (shell()->status);
    if(argc < 2 && !argv[1])
    {
        se.list = creer_envi(env);
        ft_list_remove_if(&se.list,"OLDPWD");
        while(1)
        {
            handle_signal(SIG_DEFAULT);
            line = get_user_input(line);
            tree = parse(line);
            if(tree)
            {
                if(se.check_sigint==0)
                    execution(tree);
                node_del(&tree);//parsing
            }
            free(line);
        }
        return(0);
    }
}

