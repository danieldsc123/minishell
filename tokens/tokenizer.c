/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:43 by danielda          #+#    #+#             */
/*   Updated: 2025/02/22 19:45:47 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_operator(char *input, t_token **tokens, int *i) //Identifica operadores (|, <, >, <<, >>) e chama get_redirs_token() se necessário.
{
	if (input[*i] == '|')
		add_token(tokens, PIPE, "|");
	else if (input[*i] == '<' || input[*i] == '>')
		get_redirs_token(input, tokens, i);
	(*i)++;
}

void	get_word(char *input, t_token **tokens, int *i) //Captura palavras (comandos, argumentos, arquivos).
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

void	get_redirs_token(char *input, t_token **tokens, int *i) //Trata redirecionadores (<, >, <<, >>) corretamente.
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
