/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:22:47 by kesaitou          #+#    #+#             */
/*   Updated: 2025/12/01 13:06:06 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_token(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_ifs(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	is_sq_dq(char **c, t_state *state)
{
	if (**c == '\'')
	{
		*state = STATE_SQUOTE;
		(*c)++;
		return (1);
	}
	else
	{
		*state = STATE_DQUOTE;
		(*c)++;
		return (1);
	}

	return (0);
}

int		push_token()
{
	
	
	
	
}

char	my_lex(char *input)
{
	t_lexer	lex;

	lex.c_list;
	lex.token;
	lex.state = STATE_GENERAL;
	while (*input)
	{
		if (lex.state == STATE_GENERAL)
		{
				if (*input == '\'')
				{
					lex.state = STATE_SQUOTE;
					input++;
					continue;
				}
				else if (*input == '"')
				{
					lex.state = STATE_DQUOTE;
					input++;
					continue;
				}
				else if (is_ifs(*input))
				{
					list_to_string(lex.c_list)
					skip_ifs();
				}
				else if (*input == '\\')
				{
					if (*(input + 1) != '\0')
					{
						push_token(*(input + 1));
						input += 2;
					}
				}
				else
				{
					push_token();
				}
				
				
		}
		else if (lex.state == STATE_SQUOTE)
		{
			if (*input == '\'')
			{
				lex.state = STATE_GENERAL;
			}
			else

		}
		else if (lex.state == STATE_DQUOTE)
		{
			if (*input == '"')
			{
				commit_token();
				lex.state = STATE_DQUOTE;
				
			}
			

		}
		else
			break;
		
	}








}

// t_token	*lexer(char *input)
// {
// 	t_token	*curr;
// 	t_token	*new;
// 	char			*tmp;

// 	curr = NULL;
// 	new = NULL;
// 	while (*input)
// 	{
// 		curr = new;
// 		skip_ifs();
// 		tmp = get_token_list(input); //ここでトークンの次の文字までポインタを勧めてる
// 		if (!tmp)
// 			return (NULL);
// 		lstnew(tmp);
// 		lstadd_back(&curr, new);
// 	}
// 	return (curr);
// }

int	main(void)
{

	
}

/*
	inputがヌルになるまでループして、状態によって分岐させる
	3状態の分岐を作ってcontinueで制御する



	[

		ls       -l    -a

		echo     hello

		ls|grep

		cat<infile>>outfile

		echo 'hello      world'

		echo "ls | cat"

		echo "'hello'"

		echo ""

		abc'def'"ghi"

		echo "$USER" '$USER'

		awk '{print $1}'
							]




	int lexer()
	{
		t_token curr;
		t_token new;

		new = NULL;
		while(*input)
		{
			curr = new;
			skip_ifs();
			new = get_token_list(); //ここでトークンの次の文字までポインタを勧めてる
			if(!new)
				return (ERROR);
			lst_add_back(curr, new);
			input++;　　
		}



	}


*/
