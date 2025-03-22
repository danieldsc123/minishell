/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:35:55 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/22 00:23:58 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executa múltiplos comandos em um pipeline
void	exec_multiple(int cmd_count, t_exec_cmd *cmds)
{
	int	pipes[2];
	int	prev_fd;
	int	i;

	prev_fd = -1;
	i = 0;
	while (i < cmd_count)
	{
		if (i < cmd_count - 1)
			pipe(pipes);
		cmds[i].pid = fork();
		if (cmds[i].pid == 0)
			setup_child_process(&cmds[i], prev_fd, pipes, (i == cmd_count - 1));
		if (prev_fd != -1)
			close(prev_fd);
		close(pipes[1]);
		prev_fd = pipes[0];
		i++;
	}
	while (cmd_count--)
		wait(NULL);
}

// Configura processo filho
void	setup_child_process(t_exec_cmd *cmd, int prev_fd, int *pipes, int last)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (!last)
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[1]);
	}
	check_redirects(cmd);
	execve(cmd->cmd, cmd->args, cmd->envp);
	perror("execve");
	exit(127);
}
