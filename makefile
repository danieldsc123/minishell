# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 18:58:16 by danielda          #+#    #+#              #
#    Updated: 2025/03/13 20:54:28 by daniel-da        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Compilador e flags
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I./inc

# Diretórios e arquivos
SRCS = \
    main.c \
    tokens/lexer.c \
    tokens/tokenizer.c \
    tokens/tokens.c \
    tokens/token_utils.c \
    tokens/syntax_error.c \
    tokens/quotes.c \
    parser/parser_utils.c \
    parser/parser.c \
    parser/syntax_error_p.c \
	expansor/exp_utils.c \
	expansor/expand_env.c \
	expansor/expander.c \
	expansor/remove_quotes.c \
	expansor/utils.c \
	loop_minishell/execult_mini.c \
	builtins/ft_cd.c builtins/ft_echo.c \
	builtins/ft_env.c builtins/ft_exit.c builtins/ft_export.c \
	builtins/ft_pwd.c builtins/ft_unset.c \
	env/env_utils.c env/env_operations.c

OBJS = $(SRCS:.c=.o)

# Bibliotecas externas
LIBFT = ./inc/libft/libft.a
LIBFT_DIR = ./inc/libft

# Bibliotecas necessárias para readline
LDFLAGS = -L/usr/local/lib -lreadline -lhistory

# Comandos
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@echo "✅ Compilação concluída!"

%.o: %.c inc/minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "🧹 Objetos removidos!"

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "🗑️  Executável removido!"

re: fclean all

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re valgrind
