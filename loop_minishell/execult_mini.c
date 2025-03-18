/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execult_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:27:04 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/18 02:04:06 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_input(char *input, t_env *env)
{
	t_token	*tokens;
	t_cmd	*cmds;

	if (*input)
		add_history(input);
	if (check_close_quotes(input))
		return (free(input));
	input = expand_input(input, env);
	tokens = lexer(input);
	if (check_syntax_errors(tokens, input))
	{
		free_tokens(tokens);
		return (free(input));
	}
	print_tokens(tokens);
	cmds = parse_tokens(tokens);
	if (cmds)
		print_cmds(cmds);
	free_cmd_list(cmds);
	free_tokens(tokens);
	free(input);
}

void	execute_minishell(t_env *env)
{
	char	*input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		process_input(input, env);
		free_env(&env);
		clear_history();
		rl_clear_history();
	}
}
