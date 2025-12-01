/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:23:28 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/29 22:39:26 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lstsize(t_token *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

/*lexer用に改造した*/
t_token	*lstnew(char *token)
{
	t_token	*new_elem;

	new_elem = malloc(sizeof(t_token));
	if (!new_elem)
		return (NULL);
	new_elem ->type = TOKEN_EOF;
	new_elem->token = token;
	new_elem->next = NULL;
	return (new_elem);
}

t_token	*lstlast(t_token *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	lstadd_front(t_token **lst, t_token *new)
{
	new->next = (*lst);
	(*lst) = new;
}
