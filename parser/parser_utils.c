/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:33 by danielda          #+#    #+#             */
/*   Updated: 2025/03/05 20:25:32 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Criar um novo nó de comando na lista ligada
t_cmd	*cmd_new(char **args, int is_pipe, int is_redir)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = args;
	cmd->is_pipe = is_pipe;
	cmd->is_redir = is_redir;
	cmd->next = NULL;
	return (cmd);
}

//Adicionar um novo comando ao final da lista ligada.
void	cmd_add_back(t_cmd **cmds, t_cmd *new_cmd)
{
	t_cmd	*temp;

	if (!cmds || !new_cmd)
		return ;
	if (!*cmds)
	{
		*cmds = new_cmd;
		return ;
	}
	temp = *cmds;
	while (temp->next)
		temp = temp->next;
	temp->next = new_cmd;
}

//Liberar toda a memória alocada para a lista de comandos.
void	free_cmd_list(t_cmd *cmds)
{
	t_cmd	*temp;

	while (cmds)
	{
		temp = cmds;
		cmds = cmds->next;
		free(temp->args);
		free(temp);
	}
}
