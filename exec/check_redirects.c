/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:39:12 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/27 01:43:46 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Gerencia redirecionamentos
void	check_redirects(t_exec_cmd *cmd)
{
	if (cmd->fd_in != -1)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != -1)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}

// void	check_redirects(t_exec_cmd *cmd)
// {
// 	if (cmd->fd_in != -1)
// 	{
// 		dup2(cmd->fd_in, STDIN_FILENO);
// 		close(cmd->fd_in);
// 	}
// 	if (cmd->fd_out != -1)
// 	{
// 		dup2(cmd->fd_out, STDOUT_FILENO);
// 		close(cmd->fd_out);
// 	}
// }
