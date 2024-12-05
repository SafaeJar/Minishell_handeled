#include "../minishell.h"

void	rdr_clear(t_rdr_node **lst)
{
	t_rdr_node	*tmp;

	tmp = NULL;
	if (!lst)
		return ;
	while (*lst && *lst != (void *)-1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->type == HERDOC)
			unlink(tmp->file);
		free((tmp->file));
		free(tmp);
	}
}

void	rdr_addback(t_rdr_node **lst, t_rdr_node *_new)
{
	t_rdr_node	*p;

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