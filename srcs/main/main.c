/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:36:49 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/05 23:00:13 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/readline.h"

int main(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			return (rl_clear_history(), 0);
		add_history(line);
		free(line);
	}
}

/*tester*/

int main(int argc, char **argv, char **envp)
{
	t_tree	*tmp;
	t_tree	*branch;
	t_pipe	info;
	t_flist	*flist;
	char	*str;
	char	*null;
	char	**cmd;

	null = (char *)NULL;
	flist = flist_new(NONE, null);
	branch = tree_new(&null, flist, PIPE);
	info = correct_info(argc, argv, envp);

	str = "ls -l -a -R";
	cmd = ft_split(str, ' ');
	tmp = tree_new(cmd, flist, COMMAND);
	tree_add_left(&branch, tmp);

	tmp = tree_new(&null, flist, PIPE);
	tree_add_right(&branch, tmp);

	str = "sort -u";
	cmd = ft_split(str, ' ');
	tmp = tree_new(cmd, flist, COMMAND);
	tree_add_left(&(branch->right), tmp);

	str = "cat -e";
	cmd = ft_split(str, ' ');
	tmp = tree_new(cmd, flist, COMMAND);
	tree_add_right(&(branch->right), tmp);

	tree_operator(branch, &info, 1);
	waitpid_plist(info.plist);
}
