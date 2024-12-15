/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_env_erors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:14:15 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/15 01:14:17 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*handle_content_allocation_error(void)
{
	printf("minishell: memory allocation failed for content!\n");
	return (NULL);
}

void	*handle_name_allocation_error(void *content)
{
	printf("minishell: memory allocation failed for name!\n");
	free(content);
	return (NULL);
}
