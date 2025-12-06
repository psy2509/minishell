/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:54:34 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/06 06:22:59 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.h"

/* this function must be in parent process*/

void	pwd(char **cmd)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ft_putendl_fd(tmp, 1);
	free(tmp);
	free_path(cmd);
	exit(0);
}

//int main(void)
//{
//	char	**str;
//	char	*tmp;
//	tmp = "pwd";
//	str = &tmp;
//	pwd(str);
//}