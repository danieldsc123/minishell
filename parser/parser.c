/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:06:46 by danielda          #+#    #+#             */
/*   Updated: 2025/03/18 01:31:06 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Lê os tokens e cria nós da lista ligada.
//Separa argumentos, detecta pipes e redirecionamentos.
//Usa cmd_add_back para adicionar o nó na lista.
// Cria e adiciona um comando à lista, mantendo a lógica principal limpa.
static int	handle_new_cmd(t_token **tokens, t_cmd **cmds)
{
	char	**args;
	int		is_pipe;
	int		is_redir;
	t_cmd	*new_cmd;

	args = get_args(tokens);
	if (!args)
		return (0);
	is_pipe = (*tokens && (*tokens)->type == PIPE);
	is_redir = (*tokens && ((*tokens)->type == REDIR_IN
				|| (*tokens)->type == REDIR_OUT));
	new_cmd = cmd_new(args, is_pipe, is_redir);
	if (!new_cmd)
	{
		free_args(args);
		return (0);
	}
	cmd_add_back(cmds, new_cmd);
	return (1);
}

t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd	*cmds;

	cmds = NULL;
	if (parse_has_errors(tokens))
		return (NULL);
	while (tokens)
	{
		if (!handle_new_cmd(&tokens, &cmds))
			continue ;
		if (tokens)
			tokens = tokens->next;
	}
	return (cmds);
}

// t_cmd	*parse_tokens(t_token *tokens)
// {
// 	t_cmd		*cmds;
// 	t_cmd		*new_cmd;
// 	char		**args;
// 	int			is_pipe;
// 	int			is_redir;

// 	cmds = NULL;
// 	if (parse_has_errors(tokens))
// 		return (NULL);
// 	while (tokens)
// 	{
// 		args = get_args(&tokens);
// 		if (!args)
// 			continue ;
// 		is_pipe = (tokens && tokens->type == PIPE);
// 		is_redir = (tokens && (tokens->type == REDIR_IN
// 					|| tokens->type == REDIR_OUT));
// 		new_cmd = cmd_new(args, is_pipe, is_redir);
// 		if (!new_cmd)
// 		{
// 			free_args(args);
// 			continue ;
// 		}
// 		cmd_add_back(&cmds, new_cmd);
// 		if (tokens)
// 			tokens = tokens->next;
// 	}
// 	return (cmds);
// }

// Conta quantos argumentos existem antes de um pipe ou redirecionamento
static int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type == WORD)
	{
		count++;
		tokens = tokens->next;
	}
	return (count);
}

//Extrai os argumentos dos tokens e retorna um array de strings
//Extrai os argumentos dos tokens e retorna um array de strings
char	**get_args(t_token **tokens)
{
	char	**args;
	int		count;
	int		i;
	t_token	*tmp;

	count = count_args(*tokens);
	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	tmp = *tokens;
	i = 0;
	while (tmp && tmp->type == WORD)
	{
		args[i] = ft_strdup(tmp->value);
		if (!args[i])
		{
			free_args(args);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	*tokens = tmp;
	return (args);
}
