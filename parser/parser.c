/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:06:46 by danielda          #+#    #+#             */
/*   Updated: 2025/03/05 20:06:54 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Lê os tokens e cria nós da lista ligada.
//Separa argumentos, detecta pipes e redirecionamentos.
//Usa cmd_add_back para adicionar o nó na lista.
t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd		*cmds;
	char		**args;
	int			is_pipe;
	int			is_redir;

	cmds = NULL;
	if (parse_has_errors(tokens))
		return (NULL);
	while (tokens)
	{
		args = get_args(&tokens);
		is_pipe = (tokens && tokens->type == PIPE);
		is_redir = (tokens && (tokens->type == REDIR_IN
					|| tokens->type == REDIR_OUT));
		cmd_add_back(&cmds, cmd_new(args, is_pipe, is_redir));
		if (tokens)
		tokens = tokens->next;
	}
	return (cmds);
}
