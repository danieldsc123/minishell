/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:20:00 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/15 00:49:03 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Recebe a entrada do usuário (input) e o ambiente (env).
//Expande variáveis dentro da entrada usando expand_variables(input, env).
//Libera a memória da entrada original e retorna a nova string expandida.
char	*expand_input(char *input, t_env *env)
{
	char	*expanded;

	if (!input || !*input)
		return (input);
	expanded = expand_variables(input, env);
	free(input);
	return (expanded);
}

// Inicializa a lista de variáveis de ambiente a partir do environ
// Retorna um ponteiro para a lista encadeada de t_env
t_env	*init_env(void)
{
	extern char	**environ;
	t_env		*env_list;
	char		**env;

	env_list = NULL;
	env = environ;
	while (*env)
	{
		add_env_var(&env_list, *env);
		env++;
	}
	return (env_list);
}

// Libera toda a memória alocada para a lista de variáveis de ambiente
void	free_env(t_env *env)
{
	t_env	*temp;

	while (env)
	{
		temp = env->next;
		free(env->name);
		env->name = NULL;
		free(env->value);
		env->value = NULL;
		free(env);
		env = temp;
	}
	env = NULL;
}

// Adiciona uma variável de ambiente à lista
void	add_env_var(t_env **env_list, char *env_str)
{
	t_env	*new_env;
	char	*equal_sign;

	new_env = malloc(sizeof(t_env));
	if (!new_env)
		return ;
	equal_sign = ft_strchr(env_str, '=');
	if (equal_sign)
	{
		new_env->name = ft_substr(env_str, 0, equal_sign - env_str);
		new_env->value = ft_strdup(equal_sign + 1);
	}
	else
	{
		new_env->name = ft_strdup(env_str);
		new_env->value = NULL;
	}
	new_env->next = *env_list;
	*env_list = new_env;
}
