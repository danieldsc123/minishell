/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execult_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:27:04 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/13 19:18:10 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Executa o loop principal do Minishell.
void	execute_minishell(t_env *env)
{
	char	*input;
	t_token	*tokens;
	t_cmd	*cmds;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		input = expand_input(input, env);
		input = remove_extra_quotes(input);
		tokens = lexer(input);
		print_tokens(tokens);
		cmds = parse_tokens(tokens);
		if (cmds)
			print_cmds(cmds);
		free_cmd_list(cmds);
		free_tokens(tokens);
		free(input);
	}
}

// void	sigint_handler(int sig)
// {
// 	(void)sig;
// 	write(1, "\nminishell> ", 12);
// }
