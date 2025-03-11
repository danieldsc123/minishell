/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:17 by danielda          #+#    #+#             */
/*   Updated: 2025/03/11 19:21:28 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ajusta o tipo de operadores (| vira PIPE, < vira REDIR_IN, etc.).
void	set_operator_type(t_token **tokens)
{
	t_token	*current;

	current = *tokens;
	while (current != NULL)
	{
		if (ft_strcmp(current->value, "|") == 0)
			current->type = PIPE;
		else if (ft_strcmp(current->value, "<") == 0)
			current->type = REDIR_IN;
		else if (ft_strcmp(current->value, ">") == 0)
			current->type = REDIR_OUT;
		else if (ft_strcmp(current->value, "<<") == 0)
			current->type = HEREDOC;
		else if (ft_strcmp(current->value, ">>") == 0)
			current->type = APPEND;
		current = current->next;
	}
}

// auxiliar da set_redir_type.
void	set_token_redir_type(t_token *current, char *value, char type)
{
	if (ft_strcmp(current->value, value) == 0)
	{
		if (type == '<')
		{
			if (ft_strcmp(value, "<<") == 0)
				current->type = HEREDOC;
			else
				current->type = REDIR_IN;
		}
		else if (type == '>')
		{
			if (ft_strcmp(value, ">>") == 0)
				current->type = APPEND;
			else
				current->type = REDIR_OUT;
		}
	}
}

//Define HEREDOC, APPEND, REDIR_IN ou REDIR_OUT.
void	set_redir_type(t_token *tokens, char type)
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		set_token_redir_type(current, "<", type);
		set_token_redir_type(current, ">", type);
		current = current->next;
	}
}

// adiciona um novo token a uma lista duplamente encadeada de tokens
t_token	*add_token(t_token **tokens, t_token_type type, char *value)
{
	t_token	*new_token;
	t_token	*current;

	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = ft_strdup(value);
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	if (*tokens == NULL)
		*tokens = new_token;
	else
	{
		current = *tokens;
		while (current->next)
			current = current->next;
		current->next = new_token;
		new_token->prev = current;
	}
	return (new_token);
}
