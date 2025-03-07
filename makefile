# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 18:58:16 by danielda          #+#    #+#              #
#    Updated: 2025/03/07 18:59:41 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Compilador e flags
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp
CC = gcc
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

OBJS = $(SRCS:.c=.o)
# SRCS = main.c tokens/lexer.c tokens/tokenizer.c tokens/tokens.c tokens/token_utils.c tokens/syntax_error.c parser/parser_utils.c parser/parser.c parser/syntax_error_p.c tokens/quotes.c
# OBJS = $(SRCS:.c=.o)

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
