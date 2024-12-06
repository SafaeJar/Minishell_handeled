#include "../minishell.h"

void	rdr_clear(t_redirect_node **lst)
{
	t_redirect_node	*tmp;

	tmp = NULL;
	if (!lst)
		return ;
	while (*lst && *lst != (void *)-1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->type == HEREDOC)
			unlink(tmp->file);
		free((tmp->file));
		free(tmp);
	}
}

void	rdr_addback(t_redirect_node **lst, t_redirect_node *_new)
{
	t_redirect_node	*p;

	p = *lst;
	if (!(*lst))
	{
		*lst = _new;
		return ;
	}
	while (p != (void *)-1 && p->next)
		p = p->next;
	if (p != (void *)-1)
	{
		p->next = _new;
		_new->next = NULL;
	}
}
