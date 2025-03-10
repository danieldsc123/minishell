/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:52:38 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/09 17:31:05 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// inicializa a expansão.
char	*expand_variables(char *input, t_env *env)
{
	t_expander	exp;
	char		*expanded;

	if (!input)
		return (NULL);
	exp.input = input;
	exp.output = ft_strdup("");
	exp.env_list = env;
	expanded = expand_loop(&exp);
	return (expanded);
}

// percorre input e substitui variáveis pelo valor correspondente.
char	*expand_loop(t_expander *exp)
{
	int		i;
	char	*var_value;

	i = 0;
	while (exp->input[i])
	{
		if (exp->input[i] == '$' && exp->input[i + 1])
		{
			var_value = expand_env_value(&exp->input[i], exp);
			exp->output = ft_strjoin_free(exp->output, var_value);
			i += var_name_len(&exp->input[i]);
		}
		else
			exp->output = ft_charjoin_free(exp->output, exp->input[i++]);
	}
	return (exp->output);
}
