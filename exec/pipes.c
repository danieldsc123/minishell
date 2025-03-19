/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:16:08 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 05:52:55 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//Gerenciamento de pipes

//Configura dup2 para redirecionar saída de um pipe.
void	pipe_redirect(int *pipes)
{
}

//Configura entrada do próximo comando.
void	dup_pipes_backup(int pipes_backup)
{
}

// Atualiza pipe para o próximo processo.
void	update_pipes_backup(int *pipes, int *pipes_backup)
{
}
