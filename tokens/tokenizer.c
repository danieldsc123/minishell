/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:43 by danielda          #+#    #+#             */
/*   Updated: 2025/02/24 19:39:25 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

//Identifica operadores (|, <, >, <<, >>) e chama get_redirs_token() se necessário.
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
	t_token	*new_token;

	while (input[*i] == ' ')
	(*i)++;
	start = *i;
	while (input[*i] && input[*i] != ' ' && input[*i] != '|'
		&& input[*i] != '<' && input[*i] != '>')
	(*i)++;
	new_token = add_token(tokens, WORD, ft_substr(input, start, *i - start));
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
	(*i)++;
}
