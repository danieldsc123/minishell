/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:26:12 by danielda          #+#    #+#             */
/*   Updated: 2025/02/24 21:28:27 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//auxiliar da forbiden_tokens
t_bool	check_forbidden(t_token *tokens, char *forbidden)
{
	if (!tokens)
		return (FALSE);
	while (tokens)
	{
		if (tokens->value && ft_strcmp(tokens->value, forbidden) == 0)
		{
			printf("Erro de sintaxe: token proibido encontrado\n");
			return (TRUE);
		}
		tokens = tokens->next;
	}
	return (FALSE);
}

// Verifica tokens proibidos (caso precise adicionar alguma regra específica)
t_bool	forbiden_token(t_token *tokens)
{
	return (check_forbidden(tokens, "proibido"));
}

// auxiliar da check_close_quotes
t_bool	check_quote_balance(char quote)
{
	if (quote)
	{
		printf("Erro de sintaxe: aspas não fechadas corretamente\n");
		return (TRUE);
	}
	return (FALSE);
}

// auxiliar da check_close_quotes
t_bool	toggle_quote(char quote, char c)
{
	if (quote && quote == c)
	{
		return (0);
	}
	if (!quote)
	{
		return (c);
	}
	return (quote);
}

// Verifica se todas as aspas foram fechadas corretamente
t_bool	check_close_quotes(char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			quote = toggle_quote(quote, input[i]);
		}
		i++;
	}
	return (check_quote_balance(quote));
}
