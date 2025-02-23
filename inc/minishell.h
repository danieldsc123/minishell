/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:00:03 by danielda          #+#    #+#             */
/*   Updated: 2025/02/23 18:40:37 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "minishell.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <readline/readline.h>
# include <readline/history.h>

// Definição dos tipos de tokens
typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND
}	t_token_type;

// Definição do tipo booleano
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// Estrutura para os tokens da entrada do usuário
typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

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
int		main(void);

// Verificações de erro
t_bool	check_start_pipe(t_token *tokens);
t_bool	check_op_op(t_token *tokens);
t_bool	check_end_op(t_token *tokens);
t_bool	check_end_operator(t_token *token);
t_bool	forbiden_token(t_token *tokens);
t_bool	check_forbidden(t_token *tokens, char *forbidden);
t_bool	check_close_quotes(char *input);
t_bool	toggle_quote(char quote, char c);
t_bool	check_quote_balance(char quote);
t_bool	check_syntax_errors(t_token *tokens, char *input);

#endif
