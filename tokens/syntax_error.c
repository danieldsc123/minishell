/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:50:27 by danielda          #+#    #+#             */
/*   Updated: 2025/02/23 18:35:26 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Verifica se a entrada começa com um pipe
t_bool	check_start_pipe(t_token *tokens)
{
	if (tokens && tokens->type == PIPE)
	{
		printf("Erro de sintaxe: pipe no início da linha\n");
		return (TRUE);
	}
	return (FALSE);
}

// Verifica se há operadores duplicados inválidos, como ||, <<>, etc.
t_bool	check_op_op(t_token *tokens)
{
	while (tokens && tokens->next)
	{
		if ((tokens->type >= PIPE && tokens->type <= APPEND)
			&& (tokens->next->type >= PIPE && tokens->next->type <= APPEND))
		{
			printf("Erro de sintaxe: operadores consecutivos inválidos\n");
			return (TRUE);
		}
		tokens = tokens->next;
	}
	return (FALSE);
}

// auxiliar da check_end_op
t_bool	check_end_operator(t_token *token)
{
	if (token && (token->type >= PIPE && token->type <= APPEND))
	{
		printf("Erro de sintaxe: operador no final da linha\n");
		return (TRUE);
	}
	return (FALSE);
}

// Verifica se a entrada termina com um operador inválido
t_bool	check_end_op(t_token *tokens)
{
	if (!tokens)
		return (FALSE);
	while (tokens->next)
	tokens = tokens->next;
	return (check_end_operator(tokens));
}

// Verifica tokens proibidos (caso precise adicionar alguma regra específica)
t_bool	forbiden_token(t_token *tokens)
{
	return (check_forbidden(tokens, "proibido"));
}
