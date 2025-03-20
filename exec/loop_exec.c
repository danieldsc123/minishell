/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:22:27 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/20 00:40:40 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_exec_cmd *cmd, int cmd_count)
{
	if (cmd_count == 1)
		exec_single(cmd);
	else
		exec_multiple(cmd_count, cmd);
}

void	setup_minishell_execution(t_cmd *cmds)
{
	t_exec_cmd	*exec_cmds;
	int			cmd_count;

	cmd_count = count_commands(cmds);
	exec_cmds = convert_to_exec_cmds(cmds);
	if (!exec_cmds)
		return ;
	handle_signals();
	execute_command(exec_cmds, cmd_count);
	update_exit_status(exec_cmds[cmd_count - 1].fd_out);
	free_exec_cmds(exec_cmds, cmd_count);
}

int	count_commands(t_cmd *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

t_exec_cmd	*convert_to_exec_cmds(t_cmd *cmds)
{
	t_exec_cmd	*exec_cmds;
	int			count;
	int			i;

	count = count_commands(cmds);
	i = 0;
	exec_cmds = malloc(sizeof(t_exec_cmd) * count);
	if (!exec_cmds)
		return (NULL);
	while (cmds)
	{
		exec_cmds[i].cmd = ft_strdup(cmds->cmd);
		exec_cmds[i].args = ft_split(cmds->args, ' ');
		exec_cmds[i].envp = cmds->envp;
		exec_cmds[i].is_builtin = is_builtin(exec_cmds[i].cmd);
		exec_cmds[i].fd_in = cmds->fd_in;
		exec_cmds[i].fd_out = cmds->fd_out;
		i++;
		cmds = cmds->next;
	}
	return (exec_cmds);
}

void	free_exec_cmds(t_exec_cmd *exec_cmds, int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		free(exec_cmds[i].cmd);
		free(exec_cmds[i].args);
		i++;
	}
	free(exec_cmds);
}
