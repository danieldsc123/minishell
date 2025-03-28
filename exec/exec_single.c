/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:46:22 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/27 23:22:58 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// // Executa um comando único (builtin ou externo)
// void	exec_single(t_exec_cmd *cmd, t_env *env)
// {
// 	char	**envp;

// 	if (cmd->is_builtin)
// 	{
// 		exec_builtin(cmd, env);
// 		return ;
// 	}
// 	envp = convert_env_to_array(env);
// 	cmd->pid = fork();
// 	if (cmd->pid == 0)
// 	{
// 		check_redirects(cmd);
// 		if (execve(cmd->cmd, cmd->args, envp) == -1)
// 		{
// 			perror("execve");
// 			exit(127);
// 		}
// 	}
// 	else if (cmd->pid > 0)
// 	{
// 		waitpid(cmd->pid, &cmd->status, 0);
// 		update_exit_status(cmd->status);
// 	}
// 	else
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	free(envp);
// }

void	exec_single(t_exec_cmd *cmd, t_env *env)
{
	if (cmd->is_builtin)
	{
		exec_builtin(cmd, env);
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
// // Função para contar o número de variáveis de ambiente
// int	count_env_vars(t_env *env)
// {
// 	int count = 0;

// 	while (env)
// 	{
// 		count++;
// 		env = env->next;
// 	}
// 	return count;
// }

// // Converte a lista de variáveis de ambiente (t_env) para um array char **
// char	**convert_env_to_array(t_env *env)
// {
// 	int i = 0;
// 	int env_count = count_env_vars(env);
// 	char **envp = (char **)malloc(sizeof(char *) * (env_count + 1));
// 	if (!envp)
// 	{
// 		perror("malloc");
// 		exit(1);
// 	}
// 	while (env)
// 	{
// 		envp[i] = ft_strdup(env->key_val);
// 		if (!envp[i])
// 		{
// 			perror("malloc");
// 			exit(1);
// 		}
// 		env = env->next;
// 		i++;
// 	}
// 	envp[i] = NULL;
// 	return (envp);
// }

