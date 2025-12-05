/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:09:37 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/05 17:44:49 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

int	word_len(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (is_token_type(&str[i]) != TOKEN_WORD)
			return (i);
		if (is_quote(str[i]))
		{
			tmp = quote_len(&str[i]);
			if (tmp < 0)
				return (ERROR);
			i += tmp + 1;
		}
		i++;
	}
	return (i);
}

static int	is_ifs(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ifs_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_ifs(str[i]))
		i++;
	return (i);
}

int	count_redirect(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_token_type(&str[i]) != TOKEN_WORD)
		{
			if (is_token_type(&str[i]) == TOKEN_APPEND
				|| is_token_type(&str[i]) == TOKEN_HEREDOC)
				i++;
			count++;
			i++;
		}
		i += ifs_len(&str[i]);
		i += word_len(&str[i]);
		i += ifs_len(&str[i]);
	}
	return (count);
}

//t_flist	*make_flist(char *str)
//{
//	t_file_type	ftype;
//	char		*fname;

//	if (is_token_type(str) == TOKEN_REDIRECT_OUT)
//		ftype = OUTFILE;
//	else if (is_token_type(str) == TOKEN_APPEND)
//		ftype = APPEND;
//	else if (is_token_type(str) == TOKEN_REDIRECT_IN)
//		ftype = INFILE;
//	else if (is_token_type(str) == TOKEN_HEREDOC)
//	{
//		fname =
//		ftype = INFILE
//	}

//}

//int main(void)
//{
//	char *str;

//	str = ">>\\c\"|<\" <d <<e<<a>>c<<";
//	printf("%s, %d\n",str, count_redirect(str));
//}
