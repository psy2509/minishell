# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 23:20:38 by kesaitou          #+#    #+#              #
#    Updated: 2025/12/02 23:21:36 by kesaitou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra

INCS = includes
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBDIR = $(LIBFTDIR)
LDFLAGS = -L $(LIBDIR)
LDLIBS = -lft -lreadline

MAND_SRCS = srcs/cmd_echo.c\
			srcs/cmd_pwd.c\
			srcs/cmd_cd.c\
			srcs/readline.c\
			srcs/tree_parse.c\
			srcs/tree_fd.c\
			srcs/tree_operate.c\
			srcs/tree_cmd.c\
			srcs/util_tree.c\
			srcs/util_error.c\
			srcs/lexer.c\
			srcs/lexer_utils.c\
			srcs/token_list_utils.c\
			srcs/char_list_utils.c\


			


MAND_OBJS = $(MAND_SRCS:.c=.o)


all : $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME):$(MAND_OBJS) $(LIBFT)
	$(CC) $(MAND_OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

bonus: all

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


clean:
	rm -f $(MAND_OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re