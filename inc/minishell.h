/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:00:51 by danielda          #+#    #+#             */
/*   Updated: 2025/03/18 23:24:50 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "struct_tokens.h"
# include "token_functions.h"

# include "parser_struct.h"
# include "parser_functions.h"

# include "expansor_struct.h"
# include "expansor_functions.h"

# include "functions_loop_minishel.h"

# include "builtins.h"

// struct minishell
// {
// 	/* data */
// };

#endif