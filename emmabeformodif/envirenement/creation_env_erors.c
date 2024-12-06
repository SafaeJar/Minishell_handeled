/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_env_erors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:04:03 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/06 17:04:04 by sjarfi           ###   ########.fr       */
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
