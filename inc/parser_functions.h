/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:18:18 by danielda          #+#    #+#             */
/*   Updated: 2025/03/12 00:44:59 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_FUNCTIONS_H
# define PARSER_FUNCTIONS_H

// Funções principais
t_cmd	*parse_tokens(t_token *tokens);
void	free_cmd_list(t_cmd *cmds);

// Funções auxiliares
t_cmd	*cmd_new(char **args, int is_pipe, int is_redir);
void	cmd_add_back(t_cmd **cmds, t_cmd *new_cmd);
void	print_cmds(t_cmd *cmds);
char	**get_args(t_token **tokens);
void	free_args(char **args);

// Verificações de erro
int		parse_has_errors(t_token *tokens);

#endif