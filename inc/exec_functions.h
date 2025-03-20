/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:03 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/20 19:06:41 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_FUNCTIONS_H
# define EXEC_FUNCTIONS_H

// Prototipação das funções
void		check_redirects(t_exec_cmd *cmd);
void		exec_builtin(t_exec_cmd *cmd);
void		exec_single(t_exec_cmd *cmd);
void		exec_multiple(int cmd_count, t_exec_cmd *cmds);
void		setup_child_process(t_exec_cmd *cmd, int prev_fd, int *pipes);
void		handle_signals(void);
void		update_exit_status(int status);
void		setup_minishell_execution(t_cmd *cmds);
void		execute_command(t_exec_cmd *cmd, int cmd_count);
void		free_exec_cmds(t_exec_cmd *exec_cmds, int cmd_count);
int			count_commands(t_cmd *cmds);
t_exec_cmd	*convert_to_exec_cmds(t_cmd *cmds);

#endif