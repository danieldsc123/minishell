/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:45 by danielda          #+#    #+#             */
/*   Updated: 2025/02/21 15:20:59 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_token	*lexer(char *input)
{
	t_token	*token;
	t_token	*head;
	t_token	*prev;
	int		i;

	i = 0;
	head = NULL;
	prev = NULL;
	while (input[i])
	{
		token = new_token(input, &i);
		if (token == NULL)
			return (NULL);
		if (prev)
			prev->next = token;
		else
			head = token;
		prev = token;
	}
	return (head);
}
