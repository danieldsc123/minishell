/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:38:27 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 23:18:15 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//Execução de builtins

//verifica se o comando recebido é um built-in (um comando interno do shell)
// se for, executa a função correspondente.
void	exec_builtin(t_exec_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		ft_cd(cmd->args);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		ft_pwd(cmd->args);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		ft_echo(cmd->args);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		ft_export(cmd->args);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		ft_unset(cmd->args);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		ft_env(cmd->args);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		ft_exit(cmd->args);
}
