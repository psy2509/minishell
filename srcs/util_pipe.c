/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naoki <naoki@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 03:43:18 by naoki             #+#    #+#             */
/*   Updated: 2025-12-01 03:43:18 by naoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

static	t_pid	*pid_new(pid_t pid)
{
	t_pid	*plist;

	plist = (t_pid *)ft_calloc(sizeof(t_pid), 1);
	if (!plist)
		return (NULL);
	plist->pid = pid;
	return (plist);
}

void	pid_add_back(pid_t **plist, pid_t pid)
{
	t_pid	*tmp;
	
	if (!*plist)
	{
		*plist = pid_new(pid);
		return ;		
	}
	tmp = *plist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = pid_new(pid);
	if (!tmp->next)
	{
		free_pid(plist);
		plist = NULL;
	}
}

void	free_pid(t_pid *plist)
{
	t_pid	*tmp;

	if (!plist)
		return ;
	tmp = plist;
	while (plist)
	{
		tmp = tmp->next;
		free(plist);
		plist = tmp;
	}
}