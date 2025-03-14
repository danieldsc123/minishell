/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:03:45 by danielda          #+#    #+#             */
/*   Updated: 2025/03/14 01:58:36 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmds(t_cmd *cmds)
{
	int	i;

	while (cmds)
	{
		printf("Command: ");
		i = 0;
		while (cmds->args && cmds->args[i])
		{
			printf("%s ", cmds->args[i]);
			i++;
		}
		printf("\nIs Pipe: %d, Is Redir: %d\n", cmds->is_pipe, cmds->is_redir);
		cmds = cmds->next;
	}
}

int	main(void)
{
	t_env	*env;

	env = init_env();
	execute_minishell(env);
	// free_env_vars(env);
	free_env(env);
	return (0);
}
