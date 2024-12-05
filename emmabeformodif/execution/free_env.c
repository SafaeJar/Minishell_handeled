#include "../minishell.h"

// void	delete_env(void)
// {
// 	t_envi_node	*node;
// 	t_envi_node	*next;

// 	node = se.list;
// 	while(node)
// 	{
// 		next = node->next;
// 		if(node->name)
// 		{
// 			free(node->name);
// 			node->name = NULL;
// 		}
// 		if(node->content)
// 		{
// 			free(node->content);
// 			node->content = NULL;
// 		}
// 		node->len = 0;
// 		free(node);
// 		node = next;
// 	}
// 	se.list = NULL; 
// }
