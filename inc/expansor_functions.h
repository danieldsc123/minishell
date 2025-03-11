/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:02:51 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/11 07:12:50 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_FUNCTIONS_H
# define EXPANSOR_FUNCTIONS_H

int		is_valid_var_char(char c, int first);
int		var_name_len(char *str);
int		find_var_position(char *input, char *var_name);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_charjoin_free(char *s1, char c);
char	*get_var_name(char *str);
char	*get_env_value(char *var_name, t_env *env);
char	*replace_var(char *input, char *var_name, char *value);
char	*expand_variables(char *input, t_env *env);
char	*remove_extra_quotes(char *str);
char	*expand_env_value(char *str, t_expander *exp);
char	*expand_loop(t_expander *exp);
char	*ft_strjoin_three(char *s1, char *s2, char *s3);
char	*expand_input(char *input, t_env *env);
void	execute_minishell(t_env *env);
t_env	*init_env(void);
void	free_env(t_env *env);
void	add_env_var(t_env **env_list, char *env_str);

#endif