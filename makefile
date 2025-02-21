# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 15:06:45 by danielda          #+#    #+#              #
#    Updated: 2025/02/21 15:44:36 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = minishell

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Diretórios
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Bibliotecas
LIBS = -lreadline -L/usr/local/lib -I/usr/local/include

# Arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.c)

# Arquivos objeto
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Regra padrão
all: $(NAME)

# Compila o programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

# Diretórios da Libft                                                                                    
LIBFT_DIR = ./library/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/include

# Compila arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(LIBFT) -I$(INCDIR) -c $< -o $@

# Cria o diretório de objetos se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Limpeza
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
