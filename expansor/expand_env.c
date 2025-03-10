/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:05:24 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/09 19:04:51 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Retorna o valor de uma variável de ambiente.
char	*get_env_value(char *var_name, t_env *env)
{
	if (!var_name || !env)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->name, var_name) == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}

//procura uma variável de ambiente (indicada por $) dentro de uma string.
int	find_var_position(char *input, char *var_name)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == var_name[0])
		{
			j = 1;
			while (var_name[j] && input[i + j] == var_name[j])
				j++;
			if (!var_name[j])
				return (i);
		}
		i++;
	}
	return (-1);
}

//Substitui uma variável pelo seu valor na string original
char	*replace_var(char *input, char *var_name, char *value)
{
	char	*before;
	char	*after;
	char	*new_str;
	int		pos;

	pos = find_var_position(input, var_name);
	if (pos == -1)
		return (ft_strdup(input));
	before = ft_substr(input, 0, pos);
	after = ft_strdup(&input[pos + ft_strlen(var_name) + 1]);
	new_str = ft_strjoin_three(before, value, after);
	free(before);
	free(after);
	return (new_str);
}

//Se a variável for $?, retorna o código de saída.
char	*expand_env_value(char *str, t_expander *exp)
{
	char	*var_name;
	char	*var_value;

	if (str[1] == '?')
		return (ft_itoa(exp->status_code));
	var_name = get_var_name(&str[1]);
	var_value = get_env_value(var_name, exp->env_list);
	free(var_name);
	return (var_value);
}

//Junta três strings em uma nova e libera as originais.
char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*new_str;
	char	*temp;

	if (!s1 || !s2 || !s3)
		return (NULL);
	temp = ft_strjoin(s1, s2);
	new_str = ft_strjoin(temp, s3);
	free(temp);
	free(s1);
	free(s2);
	return (new_str);
}
