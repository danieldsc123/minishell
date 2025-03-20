/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    exec_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:46:22 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 23:12:57 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//executa um único comando no shell
//com o objetivo de verificar se o comando é interno ou externo
//em caso de ser um comando externo, cria um processo filho para executá-lo
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
		exit(127);
	}
	waitpid(cmd->pid, &cmd->fd_out, 0);
	update_exit_status(cmd->fd_out);
}
