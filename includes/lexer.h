/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:55:34 by kesaitou          #+#    #+#             */
/*   Updated: 2025/12/01 07:18:09 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_token_type
{
	TOKEN_WORD = 0,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	TOKEN_EOF // リストのヌル文字みたいな意味

}						t_token_type;

typedef enum e_state
{
	STATE_GENERAL = 0,
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_ERROR,
}						t_state;

typedef struct s_token
{
	char				*token;
	enum e_token_type	type;
	struct s_token_list	*next;
}						t_token;

/*　　一文字ずつ生成していき最終的に連結してトークンにする　　*/
typedef struct s_char_list
{
	char				c;
	struct s_char_list	*next;

}						t_char_list;

typedef	struct s_lexer
{
	t_state		state;
	t_token		*token;
	t_char_list	*c_list;
	
}	t_lexer;



void    append_char(t_char_list **list, char c);
char *list_to_string(t_char_list *list);


void					lstadd_front(t_token **lst, t_token *new);
void					lstadd_back(t_token **lst, t_token *new);
int						lstsize(t_token *lst);
t_token			*lstlast(t_token *lst);
t_token			*lstnew(char *token);
void					lstclear(t_token **lst, void (*del)(void *));
void					lstdelone(t_token *lst, void (*del)(void *));
t_token			*lstmap(t_token *lst, void *(*f)(void *),
							void (*del)(void *));
void					lstiter(t_token *lst, void (*f)(void *));
