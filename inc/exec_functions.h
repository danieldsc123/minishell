/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:03 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 03:24:09 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_FUNCTIONS_H
# define EXEC_FUNCTIONS_H

// Funções principais
void	execute_command(t_command *cmd);
char	*find_executable(const char *command);
int		handle_fork(t_command *cmd);
void	execute_builtin(t_command *cmd);

// Funções auxiliares
char	*get_path_from_env(char **env);
void	free_split(char **arr);
void	handle_error(const char *msg);
void	split_path(char *path);

#endif