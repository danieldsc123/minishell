/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:35:55 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/20 19:06:30 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//AUXILIAR
void	setup_child_process(t_exec_cmd *cmd, int prev_fd, int *pipes)
{
	int	last;

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
	exit(127);
}

//responsável por executar múltiplos comandos encadeados com pipes (|)
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
			setup_child_process(&cmds[i], prev_fd, pipes, i == cmd_count - 1);
		if (prev_fd != -1)
			close(prev_fd);
		close(pipes[1]);
		prev_fd = pipes[0];
		i++;
	}
	while (cmd_count--)
		wait(NULL);
}

// void	exec_multiple(int cmd_count, t_exec_cmd *cmds)
// {
// 	int	pipes[2];
// 	int	prev_fd;
// 	int	i;

// 	prev_fd = -1;
// 	i = 0;
// 	while (i < cmd_count)
// 	{
// 		if (i < cmd_count - 1)
// 			pipe(pipes);
// 		cmds[i].pid = fork();
// 		if (cmds[i].pid == 0)
// 		{
// 			if (prev_fd != -1)
// 			{
// 				dup2(prev_fd, STDIN_FILENO);
// 				close(prev_fd);
// 			}
// 			if (i < cmd_count - 1)
// 			{
// 				dup2(pipes[1], STDOUT_FILENO);
// 				close(pipes[1]);
// 			}
// 			check_redirects(&cmds[i]);
// 			execve(cmds[i].cmd, cmds[i].args, cmds[i].envp);
// 			exit(127);
// 		}
// 		if (prev_fd != -1)
// 			close(prev_fd);
// 		close(pipes[1]);
// 		prev_fd = pipes[0];
// 		i++;
// 	}
// 	while (cmd_count--)
// 		wait(NULL);
// }
