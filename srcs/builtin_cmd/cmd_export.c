/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 06:21:49 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/06 06:47:49 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.h"

int	count_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int	export(char **cmd, t_pipe *info)
{
	char	**new_env;
	char	*tmp;
	int		i;

	i = count_env(info->envp);
	tmp = ft_strchr(cmd[1], '=');
	if (!tmp || tmp == cmd[1])
		return (free_cmd(cmd), ERROR);
	new_env = (char **)ft_calloc(i + 2, sizeof(char *));
	new_env[i + 1] = ft_strdup(cmd[1]);
	while (i >= 0)
	{
		new_env[i] = ft_strdup(info->envp[i]);
		i--;
	}
	info->envp = new_env;
	return (SUCCESS);
}
