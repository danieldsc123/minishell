/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:17 by danielda          #+#    #+#             */
/*   Updated: 2025/02/22 20:38:29 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_operator_type(t_token **tokens) //Ajusta o tipo de operadores (| vira PIPE, < vira REDIR_IN, etc.).
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

void	set_redir_type(t_token *tokens, char type) //Define HEREDOC, APPEND, REDIR_IN ou REDIR_OUT.
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		if ((type == '<' && ft_strcmp(current->value, "<") == 0))
		{
			current->type = REDIR_IN;
			break ;
		}
		else if ((type == '>' && ft_strcmp(current->value, ">") == 0))
		{
			current->type = REDIR_OUT;
			break ;
		}
		else if ((type == '<' && ft_strcmp(current->value, "<<") == 0))
		{
			current->type = HEREDOC;
			break ;
		}
		else if ((type == '>' && ft_strcmp(current->value, ">>") == 0))
		{
			current->type = APPEND;
			break ;
		}
		current = current->next;
	}
}

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
