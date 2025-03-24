/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    exec_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:46:22 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/23 21:06:44 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executa um comando único (builtin ou externo)
void	exec_single(t_exec_cmd *cmd)
{
	if (cmd->is_builtin)
	{
		exec_builtin(cmd);
		return ;
	}
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		check_redirects(cmd);
		execve(cmd->cmd, cmd->args, cmd->envp);
		perror("execve");
		exit(127);
	}
	waitpid(cmd->pid, &cmd->status, 0);
	update_exit_status(cmd->status);
}
