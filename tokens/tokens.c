/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:08:18 by danielda          #+#    #+#             */
/*   Updated: 2025/02/21 16:45:00 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h> // Para strndup
#include <stdlib.h> // Para malloc e free

t_token	*allocate_token(t_token **tokens, char *input, int start, int end)
{
	t_token	*new_token;
	t_token	*current;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		free(new_token)
		return (NULL);
	}
	new_token->value = ft_strndup(input + start, end - start);
	if (!new_token->value)
	{
		free(new_token);
		return (NULL);
	}
	new_token->next = NULL;
	if (*tokens == NULL)
	{
		*tokens = new_token;
	}
	else
	{
		current = *tokens;
		while (current->next != NULL)
			current = current->next;
		current->next = new_token;
	}
	return (new_token);
}
