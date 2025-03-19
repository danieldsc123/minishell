/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:37:26 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 03:15:06 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Função para executar o comando
void	execute_command(t_command *cmd)
{
}

//Vai encontrar o caminho completo do comando executável, buscando no PATH.
char	find_executable(const char *cmd)
{
}

//Função responsável por executar os comandos internos (echo, cd, pwd, etc.).
void	execute_builtin(t_command *cmd)
{
}
