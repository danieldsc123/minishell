/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:22:27 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/23 21:32:26 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executa um ou múltiplos comandos, dependendo da quantidade de comandos.
void	execute_command(t_exec_cmd *cmds, int cmd_count)
{
	if (cmd_count == 1)
		exec_single(cmds);
	else
		exec_multiple(cmd_count, cmds);
}

// Configura e inicia a execução dos comandos do Minishell.
void	setup_minishell_execution(t_cmd *cmds)
{
	t_exec_cmd	*exec_cmds;
	int			cmd_count;
	t_env		*envp;

	envp = init_env();
	if (!envp)
		return ;
	cmd_count = count_commands(cmds);
	exec_cmds = convert_to_exec_cmds(cmds, envp);
	if (!exec_cmds)
		return ;
	handle_signals();
	execute_command(exec_cmds, cmd_count);
	update_exit_status(exec_cmds[cmd_count - 1].status);
	free_exec_cmds(exec_cmds, cmd_count);
}

// Conta quantos comandos existem na lista encadeada.
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

//Converte lista de comandos(t_cmd) para uma estrutura t_exec_cmd para execução.
t_exec_cmd	*convert_to_exec_cmds(t_cmd *cmds, t_env *envp)
{
	t_exec_cmd	*exec_cmds;
	int			count;
	int			i;

	count = count_commands(cmds);
	exec_cmds = malloc(sizeof(t_exec_cmd) * count);
	if (!exec_cmds)
		return (NULL);
	i = 0;
	while (cmds)
	{
		exec_cmds[i].cmd = cmds->args[0];
		exec_cmds[i].args = cmds->args;
		exec_cmds[i].envp = envp;
		exec_cmds[i].is_builtin = is_builtin(exec_cmds[i].cmd);
		exec_cmds[i].fd_in = 0;
		exec_cmds[i].fd_out = 1;
		exec_cmds[i].status = 0;
		i++;
		cmds = cmds->next;
	}
	return (exec_cmds);
}

// t_exec_cmd	*convert_to_exec_cmds(t_cmd *cmds, t_env *envp)
// {
// 	t_exec_cmd	*exec_cmds;
// 	int			count;
// 	int			i;

// 	count = count_commands(cmds);
// 	i = 0;
// 	exec_cmds = malloc(sizeof(t_exec_cmd) * count);
// 	if (!exec_cmds)
// 		return (NULL);
// 	while (cmds)
// 	{
// 		exec_cmds[i].cmd = ft_strdup(cmds->cmd);
// 		exec_cmds[i].args = ft_split(cmds->args, ' ');
// 		exec_cmds[i].envp = envp;
// 		exec_cmds[i].is_builtin = is_builtin(exec_cmds[i].cmd);
// 		exec_cmds[i].fd_in = cmds->fd_in;
// 		exec_cmds[i].fd_out = cmds->fd_out;
// 		exec_cmds[i].exit_status = 0;
// 		i++;
// 		cmds = cmds->next;
// 	}
// 	return (exec_cmds);
// }

// Libera a memória alocada para os comandos executáveis.
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
