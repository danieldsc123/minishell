/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:21:08 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/21 23:55:49 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Atualiza status de saída
void	update_exit_status(int status)
{
	if (WIFEXITED(status))
		get_core()->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		get_core()->exit_status = 128 + WTERMSIG(status);
}
