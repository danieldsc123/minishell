/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:00:03 by danielda          #+#    #+#             */
/*   Updated: 2025/02/22 23:07:21 by danielda         ###   ########.fr       */
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

#endif
