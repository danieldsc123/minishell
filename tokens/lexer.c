/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:45 by danielda          #+#    #+#             */
/*   Updated: 2025/03/17 23:57:26 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//processa a entrada (input) do usuário e a transforma em uma lista de tokens.
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
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			get_operator(input, &head, &i);
		else
			get_word(input, &head, &i);
	}
	remove_quotes_from_tokens(head);
	return (head);
}
