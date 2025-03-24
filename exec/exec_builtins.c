/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:38:27 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/23 21:38:02 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//Execução de builtins

// Executa builtins
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
		ft_exit(ft_atoi(cmd->args[1]));
}

// Verifica se é um builtin
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}
