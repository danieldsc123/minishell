/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execult_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:27:04 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/20 00:30:02 by daniel-da        ###   ########.fr       */
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
	{
		print_cmds(cmds);
		setup_minishell_execution(cmds);
	}
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
	}
	free_env(&env);
	clear_history();
	rl_clear_history();
}
