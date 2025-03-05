/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:08:18 by danielda          #+#    #+#             */
/*   Updated: 2025/03/05 18:22:50 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Cria e adiciona um novo token à lista encadeada.
t_token	*allocate_token(t_token **tokens, char *input, int start, int end)
{
	t_token	*new_token;
	t_token	*current;
	char	*value;

	value = ft_strndup(input + start, end - start);
	if (!value)
		return (NULL);
	new_token = ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->next = NULL;
	if (*tokens == NULL)
		*tokens = new_token;
	else
	{
		current = *tokens;
		while (current->next != NULL)
			current = current->next;
		current->next = new_token;
	}
	return (new_token);
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
