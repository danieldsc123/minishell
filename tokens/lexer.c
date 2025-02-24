/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:45 by danielda          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:22 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

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
			continue ;
		}
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			get_operator(input, &head, &i);
		else
			get_word(input, &head, &i);
	}
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

// t_bool	check_syntax_errors(t_token *tokens, char *input)
// {
// 	printf("Verificando erros de sintaxe...\n");
// 	if (!tokens)
// 	{
// 		printf("Erro: Lista de tokens vazia!\n");
// 		return (FALSE);
// 	}
// 	if (check_start_pipe(tokens))
// 	{
// 		printf("Erro detectado: Pipe no início.\n");
// 		return (TRUE);
// 	}
// 	if (check_op_op(tokens))
// 	{
// 		printf("Erro detectado: Operador duplicado.\n");
// 		return (TRUE);
// 	}
// 	if (check_end_op(tokens))
// 	{
// 		printf("Erro detectado: Operador no final.\n");
// 		return (TRUE);
// 	}
// 	if (forbiden_token(tokens))
// 	{
// 		printf("Erro detectado: Token proibido.\n");
// 		return (TRUE);
// 	}
// 	if (check_close_quotes(input))
// 	{
// 		printf("Erro detectado: Aspas não fechadas.\n");
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }
