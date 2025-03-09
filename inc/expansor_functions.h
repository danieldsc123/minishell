/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:02:51 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/09 01:35:16 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

#ifndef EXPANSOR_FUNCTIONS_H
# define EXPANSOR_FUNCTIONS_H

int is_valid_var_char(char c);
char    *get_var_name(char *str);
char    *get_env_value(char *var_name, t_env *env);
char    *replace_var(char *input, char *var_name, char *value);
char    *expand_variables(char *input, t_env *env);
char    *remove_extra_quotes(char *str);

#endif