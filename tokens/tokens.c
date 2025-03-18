/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:08:18 by danielda          #+#    #+#             */
/*   Updated: 2025/03/18 00:13:16 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função geral que chama todas as verificações
t_bool	check_syntax_errors(t_token *tokens, char *input)
{
	if (check_start_pipe(tokens) || check_op_op(tokens)
		|| check_end_op(tokens) || forbiden_token(tokens)
		|| check_close_quotes(input))
		return (TRUE);
	return (FALSE);
}

//Libera a memória de todos os tokens da lista.
void	free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens != NULL)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->value);
		free(temp);
	}
}

//opcional para debug
void	print_tokens(t_token *tokens)
{
	if (!tokens)
		return ;
	printf("Tokens:\n");
	while (tokens)
	{
		printf("[%d] %s\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
}
