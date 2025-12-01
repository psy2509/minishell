/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:55:44 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/29 18:28:43 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define SUCCESS 1
# define FAIL -1
# define FIRST 2
# define LAST argc - 2

typedef enum e_tree_type
{
	PIPE = 0,
	COMMAND,
	MY_COMMAND,
}					t_tree_type;

typedef struct s_tree
{
	char			*op;
	struct s_tree	*left;
	struct s_tree	*right;
	char			**argv;
	char			*redirect_in;
	char			*redirect_out:
	t_tree_type		state;
}					t_tree;

typedef struct s_pid
{
	int				pid;
	typedef struct	*next;
}	t_pid;

typedef struct s_pipe
{
	int				argc;
	char			**envp;
	char			**argv;
	char			**path;
	int				fd_in[2];
	int				fd_out[2];
	t_pid			*plist;
}					t_pipe;

/*parse*/
t_pipe				correct_info(int argc, char **argv, char **envp);
void				free_path(char **path);

/*util_pipe*/
void				pid_add_back(pid_t **plist, pid_t pid);
void				free_pid(t_pid *plist);

#endif