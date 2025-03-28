/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:38 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/27 22:55:54 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

typedef struct s_exec_cmd
{
	char	**args;
	char	*cmd;
	t_env	**envp;
	int		is_builtin;
	int		fd_in;
	int		fd_out;
	int		status;
	pid_t	pid;
}	t_exec_cmd;

// Estrutura global para armazenar estado do shell
typedef struct s_core
{
	int	exit_status;
}	t_core;

t_core	*get_core(void);

#endif