/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:38 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 02:03:34 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

// Estruturas para o Minishell
typedef struct s_command
{
	char	**args;// Argumentos do comando
	char	*command_path;// Caminho completo do executável
	int		pipe_in;// Pipe de entrada
	int		pipe_out;// Pipe de saída
}	t_command;

#endif