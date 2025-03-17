/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:43 by danielda          #+#    #+#             */
/*   Updated: 2025/03/17 02:34:28 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Identifica operadores (|, <, >, <<, >>)e chama get_redirs_token se necessário.
void	get_operator(char *input, t_token **tokens, int *i)
{
	if (input[*i] == '|')
		add_token(tokens, PIPE, "|");
	else if (input[*i] == '<' || input[*i] == '>')
		get_redirs_token(input, tokens, i);
	(*i)++;
}

//Captura palavras (comandos, argumentos, arquivos).
void	get_word(char *input, t_token **tokens, int *i)
{
	int		start;
	char	*word;

	while (input[*i] == ' ')
		(*i)++;
	start = *i;
	while (input[*i] && input[*i] != ' ' && input[*i] != '|'
		&& input[*i] != '<' && input[*i] != '>')
	{
		if (is_quote(input[*i]))
			skip_quotes(input, i);
		else
			(*i)++;
	}
	word = ft_substr(input, start, *i - start);
	if (!word)
		return ;
	add_token(tokens, WORD, word);
	free(word);
}

//Trata redirecionadores (<, >, <<, >>) corretamente.
void	get_redirs_token(char *input, t_token **tokens, int *i)
{
	if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			add_token(tokens, HEREDOC, "<<");
			(*i)++;
		}
		else
			add_token(tokens, REDIR_IN, "<");
	}
	else if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			add_token(tokens, APPEND, ">>");
			(*i)++;
		}
		else
			add_token(tokens, REDIR_OUT, ">");
	}
}
