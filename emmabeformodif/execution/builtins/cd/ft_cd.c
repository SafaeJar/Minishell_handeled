#include "../../../minishell.h"

void go_to_newpath(const char *path,char *current_dir)
{
    char *newpwd;

    if (chdir(path) != 0)//change the current working directory of the calling process
    {
        printf("minishell: cd: %s: %s\n", path, strerror(errno));// helps in providing detailed error messages when a system call or function fails and sets errno.
        free(current_dir);
        se.exit_status = 1;
        return ;
    }
    newpwd = getcwd(NULL, 0);
    if (!newpwd)
    {
        perror("getcwd");// print a descriptive error message to stderr based on the current value of the global variable errno
        free(current_dir);
        se.exit_status = 1;
        return;
    }
    update_env_var(&se.list, "OLDPWD", current_dir);
    update_env_var(&se.list, "PWD", newpwd);
    free(current_dir);
    free(newpwd);
    se.exit_status = 0;
}

void ft_cd(char *path,int argc)
{
    t_envi_node *oldpwd;
    char *current_dir;
    
    if(argc > 2)
    {
        printf("cd: too many arguments");
        se.exit_status = 1;
        return;
    }
    oldpwd = var_find(se.list, "OLDPWD");
    current_dir = getcwd(NULL, 0);
    if (!current_dir)
    {
        perror("getcwd");
        se.exit_status = 1;
        return;
    }
    if (argc == 1 || ft_strcmp(path, "~") == 0 ||
        ft_strcmp(path, "--") == 0)
        go_to_home(current_dir);
    else if (ft_strcmp(path, "-") == 0)
        go_to_oldpath(oldpwd,current_dir);
    else
        go_to_newpath(path,current_dir);
}
