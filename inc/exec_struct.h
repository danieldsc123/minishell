/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:38 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 22:50:46 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

typedef struct s_exec_cmd
{
	char	**args;
	char	*cmd;
	char	**envp;
	int		is_builtin;
	int		fd_in;
	int		fd_out;
	pid_t	pid;
}	t_exec_cmd;

// Estrutura global para armazenar estado do shell
typedef struct s_core
{
	int	exit_status;
}	t_core;

t_core	*get_core(void);

#endif