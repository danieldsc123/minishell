/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:58:07 by danielda          #+#    #+#             */
/*   Updated: 2025/03/05 20:16:56 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Mensagem de erro genérica
void	print_parse_error(char *msg)
{
	fprintf(stderr, "Minishell: Syntax error: %s\n", msg);
}

// Verifica se o primeiro ou último token é um pipe
int	check_start_end_pipe(t_token *tokens)
{
	if (!tokens)
		return (0);
	if (tokens->type == PIPE)
	{
		print_parse_error("unexpected token `|'");
		return (1);
	}
	while (tokens->next)
		tokens = tokens->next;
	if (tokens->type == PIPE)
	{
		print_parse_error("unexpected token `|'");
		return (1);
	}
	return (0);
}

// Verifica tokens duplicados inválidos (ex: "||", "><")
int	check_invalid_token_sequence(t_token *tokens)
{
	while (tokens && tokens->next)
	{
		if ((tokens->type == PIPE && tokens->next->type == PIPE)
			|| (tokens->type == REDIR_IN && tokens->next->type == REDIR_OUT)
			|| (tokens->type == REDIR_OUT && tokens->next->type == REDIR_IN))
		{
			print_parse_error("unexpected token");
			return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}

// Verifica se há redirecionamento sem um arquivo destino
int	check_redir_without_file(t_token *tokens)
{
	while (tokens)
	{
		if ((tokens->type == REDIR_IN || tokens->type == REDIR_OUT)
			&& (!tokens->next || tokens->next->type != WORD))
		{
			print_parse_error("redirection without target");
			return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}

// Chamada principal de verificação de erros
int	parse_has_errors(t_token *tokens)
{
	if (check_start_end_pipe(tokens)
		|| check_invalid_token_sequence(tokens)
		|| check_redir_without_file(tokens))
		return (1);
	return (0);
}
