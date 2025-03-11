/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:45 by danielda          #+#    #+#             */
/*   Updated: 2025/03/11 20:14:36 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//processa a entrada (input) do usuário e a transforma em uma lista de tokens.
t_token	*lexer(char *input)
{
	t_token	*head;
	int		i;

	i = 0;
	head = NULL;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
		{
			i++;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			get_operator(input, &head, &i);
		else
			get_word(input, &head, &i);
	}
	remove_quotes_from_tokens(head);
	if (check_syntax_errors(head, input))
	{
		free_tokens(head);
		return (NULL);
	}
	return (head);
}

// Função geral que chama todas as verificações
t_bool	check_syntax_errors(t_token *tokens, char *input)
{
	if (check_start_pipe(tokens) || check_op_op(tokens)
		|| check_end_op(tokens) || forbiden_token(tokens)
		|| check_close_quotes(input))
		return (TRUE);
	return (FALSE);
}
