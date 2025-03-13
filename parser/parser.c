/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:06:46 by danielda          #+#    #+#             */
/*   Updated: 2025/03/12 18:38:18 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

// Lê os tokens e cria nós da lista ligada.
//Separa argumentos, detecta pipes e redirecionamentos.
//Usa cmd_add_back para adicionar o nó na lista.
t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd		*cmds;
	t_cmd		*new_cmd;
	char		**args;
	int			is_pipe;
	int			is_redir;

	cmds = NULL;
	if (parse_has_errors(tokens))
		return (NULL);
	while (tokens)
	{
		args = get_args(&tokens);
		if (!args)
			continue ;
		is_pipe = (tokens && tokens->type == PIPE);
		is_redir = (tokens && (tokens->type == REDIR_IN
					|| tokens->type == REDIR_OUT));
		new_cmd = cmd_new(args, is_pipe, is_redir);
		if (!new_cmd)
			free_args(args);
		cmd_add_back(&cmds, new_cmd);
		if (tokens)
			tokens = tokens->next;
	}
	return (cmds);
}

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

// void	free_args(char **args)
// {
// 	int	i;

// 	if (!args)
// 		return ;
// 	i = 0;
// 	while (args[i])
// 	{
// 		free(args[i]);
// 		i++;
// 	}
// 	free(args);
// }

// Extrai os argumentos dos tokens e retorna um array de strings
// Extrai os argumentos dos tokens e retorna um array de strings
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
	return (args);
}

// char	**get_args(t_token **tokens)
// {
// 	char	**args;
// 	int		count;
// 	int		i;

// 	count = count_args(*tokens);
// 	args = (char **)malloc(sizeof(char *) * (count + 1));
// 	if (!args)
// 		return (NULL);
// 	i = 0;
// 	while (*tokens && (*tokens)->type == WORD)
// 	{
// 		args[i] = ft_strdup((*tokens)->value);
// 		*tokens = (*tokens)->next;
// 		i++;
// 	}
// 	args[i] = NULL;
// 	free_args(*args);
// 	return (args);
// }
