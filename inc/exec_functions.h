/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:03 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 23:23:08 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_FUNCTIONS_H
# define EXEC_FUNCTIONS_H

// Prototipação das funções
void	check_redirects(t_exec_cmd *cmd);
void	exec_builtin(t_exec_cmd *cmd);
void	exec_single(t_exec_cmd *cmd);
void	exec_multiple(int cmd_count, t_exec_cmd *cmds);
void	setup_child_process(t_exec_cmd *cmd, int prev_fd, int *pipes, int last);
void	handle_signals(void);
void	update_exit_status(int status);

#endif