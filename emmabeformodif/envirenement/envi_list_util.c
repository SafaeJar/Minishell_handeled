#include "../minishell.h"

void add_dernier(t_envi_node **lst, t_envi_node *new)
{
    t_envi_node *pointeur;
    if(!new)
        return (printf("minishell:memory was not allocated!\n"), (void)0);
    if(!*lst)
    {
        *lst = new;
        return;
    }
    pointeur = lstlast(*lst);
    pointeur->next = new;
}
t_envi_node *lstlast(t_envi_node *lst)
{
    if(!lst)
        return(0);
    while((lst->next))
        lst=lst->next;
    return(lst);
}
t_envi_node *nv_node(char *content, char *name, int len)
{
    t_envi_node *s;

    s = (t_envi_node *)malloc(sizeof(t_envi_node));
    if (s == NULL)
    {
        printf("minishell: memory was not allocated for the new node!\n");
        return (NULL);
    }
    if (!name)
    {
        printf("minishell: memory was not allocated for name!\n");
        free(s);
        return (NULL);
    }
    if (!content)
    {
        printf("minishell: memory was not allocated for content!\n");
        free(name); free(s);  // Libérer le nom alloué avant de retourner
        return (NULL);
    }
    s->content = content;
    s->name = name;
    s->len = len;
    s->next = NULL;
    return (s);
}
