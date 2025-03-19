/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:03 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 06:05:35 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_FUNCTIONS_H
# define EXEC_FUNCTIONS_H

// Execução principal
void	execute_command(t_cmd *cmd);
void	exec_one_cmd(t_cmd *cmd);
void	exec_mult_cmd(int cmd_number);
void	check_exec(t_cmd *cmd);

// Execução de builtins
void	exec_builtins(t_cmd *cmd);
void	cd(char **args);
void	pwd(int fd);
void	echo(char **args, int fd);
void	exit_shell(char **args);

// Redirecionamentos
void	check_redirects(t_cmd *cmd);
int		open_input_redirection(char *filename);
int		open_output_redirection(char *filename, int append);

// Gerenciamento de pipes
void	pipe_redirect(int *pipes);
void	dup_pipes_backup(int pipes_backup);
void	update_pipes_backup(int *pipes, int *pipes_backup);

// Utilidades para execução
char	*find_executable(const char *command);
char	*get_path_from_env(char **env);
char	**split_path(char *path);
void	free_split(char **arr);

// Gerenciamento de status e processos
void	return_exit_status(void);
void	clear_and_exit_child(int status);
int		handle_fork(t_cmd *cmd);
void	execution_signals(int fork_pid);
void	wait_child(t_cmd *cmd_table, int cmd_number);

#endif