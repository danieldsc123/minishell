/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:41:38 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 06:10:38 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

typedef struct s_redir
{
	int				fd;// File descriptor para redirecionamento
	char			*filename;// Nome do arquivo redirecionado
	struct s_redir	*next;// Próximo redirecionamento (caso haja)
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;// Nome do comando
	char	**args;// Argumentos do comando
	char	**envp;// Variáveis de ambiente
	t_redir	*redir_in;// Redirecionamento de entrada (<)
	t_redir	*redir_out;// Redirecionamento de saída (>, >>)
	pid_t	fork_pid;// ID do processo filho
	int		is_builtin;// Flag para indicar se é um builtin
	int		index;// Índice do comando na pipeline
}	t_cmd;

#endif