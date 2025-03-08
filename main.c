/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:03:45 by danielda          #+#    #+#             */
/*   Updated: 2025/03/07 22:36:33 by danielda         ###   ########.fr       */
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
	char			*input;
	t_token			*tokens;
	t_cmd			*cmds;
	extern char		**environ;// fazer uma cópia das variaveis de ambiente

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		tokens = lexer(input);
		remove_quotes_from_tokens(tokens);
		print_tokens(tokens);
		cmds = parse_tokens(tokens);
		if (cmds)
			print_cmds(cmds);
		free_cmd_list(cmds);
		free_tokens(tokens);
		free(input);
	}
	return (0);
}

// int	main(void)
// {
// 	char	*input;
// 	t_token	*tokens;

// 	while (1)
// 	{
// 		input = readline("minishell> ");
// 		if (!input)
// 			break ;
// 		if (*input)
// 			add_history(input);
// 		tokens = lexer(input);
// 		print_tokens(tokens);
// 		free_tokens(tokens);
// 		free(input);
// 	}
// 	return (0);
// }
