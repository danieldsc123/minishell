/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:17 by danielda          #+#    #+#             */
/*   Updated: 2025/02/21 17:47:55 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void set_operator_type(t_token **tokens) //Ajusta o tipo de operadores (| vira PIPE, < vira REDIR_IN, etc.).
{
	t_token	*current;

	current = *tokens;
	while (current != NULL)
	{
		if (strcmp(current->value, "|") == 0)
			current->type = PIPE;
		else if (strcmp(current->value, "<") == 0)
			current->type = REDIR_IN;
		else if (strcmp(current->value, ">") == 0)
			current->type = REDIR_OUT;
		else if (strcmp(current->value, "<<") == 0)
			current->type = HEREDOC;
		else if (strcmp(current->value, ">>") == 0)
			current->type = APPEND;
		current = current->next;
	}
}
void set_redir_type(t_token *tokens, char type) //Define HEREDOC, APPEND, REDIR_IN ou REDIR_OUT.
{
}
