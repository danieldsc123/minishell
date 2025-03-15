/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:02:06 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/15 02:06:11 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_STRUCT_H
# define EXPANSOR_STRUCT_H

typedef struct s_env
{
	char			*name;// Nome da variável (ex: "PATH")
	char			*value;// Valor da variável (ex: "/usr/bin:/bin")
	struct s_env	*next;// Próximo nó da lista
}	t_env;

typedef struct s_expander
{
	char	*input;// String original a ser expandida
	char	*output;// String processada após expansão
	int		status_code;// Código de saída ($?) do último comando
	t_env	*env_list;// Lista encadeada das variáveis de ambiente
}	t_expander;

#endif