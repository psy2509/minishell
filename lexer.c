/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:22:47 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/28 21:47:53 by kesaitou         ###   ########.fr       */
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

t_token_list	*malloc_word(char *token)
{
}

t_token_list	*get_token_list(char *input)
{
	t_state	state;

	state = STATE_GENERAL;
	while (*input)
	{
		if (*input == '\'')
		{
			state = STATE_SQUOTE;
			while (*input != '\'')
			{
				input++;
				
			}
		}
		if (*input == '"')
		{
			state = STATE_DQUOTE;
		}
		else
		{
			if (*input == '\'')
			{
				state = STATE_SQUOTE;
				input++;
				continue ;
			}
			if (*input == '"')
			{
				state = STATE_DQUOTE;
				input++;
				continue ;
			}
			if (*input == '\\')
			{
			}
		}
	}
}

t_token_list	*lexer(char *input)
{
	t_token_list	*curr;
	t_token_list	*new;

	curr = NULL;
	new = NULL;
	while (*input)
	{
		curr = new;
		skip_ifs();
		new = get_token_list(input); //ここでトークンの次の文字までポインタを勧めてる
		if (!new)
			return (NULL);
		lstadd_back(&curr, new);
	}
	return (curr);
}

int	main(void)
{
}

/*
	tokenに入れるための文字列を判定してDUPしてリストにいれる




	通常モードのときにクォートが来た場合continueで戻す？
	IFSとスペースごとにトークンとして区切る

	先頭のIFSをスキップして次のIFSが出現するまで探索しトークンにする




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
		t_token_list curr;
		t_token_list new;

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
