/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:50:27 by danielda          #+#    #+#             */
/*   Updated: 2025/03/16 00:17:51 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Verifica se a entrada começa com um pipe
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

// Verifica se a entrada termina com um operador inválido
t_bool	check_end_op(t_token *tokens)
{
	if (!tokens)
		return (FALSE);
	while (tokens->next)
		tokens = tokens->next;
	if (tokens->type >= PIPE && tokens->type <= APPEND)
	{
		printf("Erro de sintaxe: operador no final da linha\n");
		return (TRUE);
	}
	return (FALSE);
}

// Verifica tokens proibidos (caso precise adicionar alguma regra específica)
t_bool	forbiden_token(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->value && ft_strcmp(tokens->value, "proibido") == 0)
		{
			printf("Erro de sintaxe: token proibido encontrado\n");
			return (TRUE);
		}
		tokens = tokens->next;
	}
	return (FALSE);
}

// Verifica se todas as aspas foram fechadas corretamente
t_bool	check_close_quotes(char *input)
{
	int		i;
	int		single_quote;
	int		double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (input[i])
	{
		if (input[i] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		else if (input[i] == '"' && single_quote == 0)
			double_quote = !double_quote;
		i++;
	}
	if (single_quote || double_quote)
	{
		printf("Erro de sintaxe: aspas não fechadas corretamente\n");
		return (TRUE);
	}
	return (FALSE);
}
