/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:21:08 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/19 23:27:40 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//deve atualizar o valor do status de saída do último comando executado
//status armazenado em uma variável global para ser usado no comando $ ?.
void	update_exit_status(int status)
{
	if (WIFEXITED(status))
		get_core()->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		get_core()->exit_status = 128 + WTERMSIG(status);
}
