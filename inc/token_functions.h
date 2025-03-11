/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:03:48 by danielda          #+#    #+#             */
/*   Updated: 2025/03/11 19:57:33 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_FUNCTIONS_H
# define TOKEN_FUNCTIONS_H

t_token	*lexer(char *input);
void	get_operator(char *input, t_token **tokens, int *i);
void	get_word(char *input, t_token **tokens, int *i);
void	get_redirs_token(char *input, t_token **tokens, int *i);
t_token	*allocate_token(t_token **tokens, char *input, int start, int end);
void	free_tokens(t_token *tokens);
void	print_tokens(t_token *tokens); // Apenas para debug
void	set_operator_type(t_token **tokens);
void	set_token_redir_type(t_token *current, char *value, char type);
void	set_redir_type(t_token *tokens, char type);
t_token	*add_token(t_token **tokens, t_token_type type, char *value);
t_bool	is_quote(char c);
void	skip_quotes(char *input, int *i);
t_bool	has_unclosed_quotes(char *input);
char	*remove_quotes(char *str);
void	remove_quotes_from_tokens(t_token *tokens);
int		main(void);

// Verificações de erro
t_bool	check_start_pipe(t_token *tokens);
t_bool	check_op_op(t_token *tokens);
t_bool	check_end_op(t_token *tokens);
// t_bool	check_end_operator(t_token *token);
t_bool	forbiden_token(t_token *tokens);
// t_bool	check_forbidden(t_token *tokens, char *forbidden);
t_bool	check_close_quotes(char *input);
t_bool	toggle_quote(char quote, char c);
// t_bool	check_quote_balance(char quote);
t_bool	check_syntax_errors(t_token *tokens, char *input);

#endif