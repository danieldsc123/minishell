/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execult_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:27:04 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/27 22:45:37 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Imprime a lista de comandos e seus argumentos
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

//Processa a entrada do usuário: expande variáveis
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
		setup_minishell_execution(cmds, env);
	}
	free_cmd_list(cmds);
	free_tokens(tokens);
	free(input);
}

// Loop principal do Minishell que lê comandos do usuário
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
