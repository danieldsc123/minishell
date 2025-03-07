/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:38 by danielda          #+#    #+#             */
/*   Updated: 2025/03/07 18:17:46 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include <stdlib.h>

typedef struct s_cmd
{
    char       **args;// Argumentos do comando
    int        is_pipe;// 1 se for pipe "|"
    int        is_redir;// 1 se for redirecionamento "<" ou ">"
    struct  s_cmd   *next;// Próximo comando na lista
}t_cmd;

#endif