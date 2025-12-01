/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:22:44 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/29 22:39:26 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstdelone(t_token *lst, void (*del)(void *))
{
	(del)(lst->token);
	free(lst);
}

void	lstclear(t_token **lst, void (*del)(void *))
{
	t_token	*current;
	t_token	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		(del)(current->token);
		free(current);
		current = next;
	}
	(*lst) = NULL;
}

