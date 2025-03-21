/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:03:45 by danielda          #+#    #+#             */
/*   Updated: 2025/03/19 00:34:07 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_builtins(t_env *env)
{
	char	*echo_args[] = {"echo", "Hello", "World", NULL};
	char	*echo_n_args[] = {"echo", "-n", "Hello", "World", NULL};
	char	*cd_args[] = {"cd", "..", NULL};
	char	*export_args[] = {"export", "TEST=123", "PATH=/usr/bin", NULL};
	char	*unset_args[] = {"unset", "TEST", NULL};
	char	*exit_args[] = {"exit", "0", NULL};

	printf("\n=== Testando echo ===\n");
	ft_echo(echo_args);
	ft_echo(echo_n_args);

	printf("\n=== Testando pwd ===\n");
	ft_pwd();

	printf("\n=== Testando cd ===\n");
	ft_cd(cd_args, env);
	ft_pwd();

	printf("\n=== Testando export ===\n");
	ft_export(export_args, env);

	printf("\n=== Testando env ===\n");
	ft_env(env);

	printf("\n=== Testando unset ===\n");
	ft_unset(unset_args, env);
	ft_env(env);

	printf("\n=== Testando exit ===\n");
	ft_exit(exit_args, env);
}

/*
int	main(void)
{
	t_env	*env;

	env = init_env();
	execute_minishell(env);
	return (0);
}
*/

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argc;
	(void)argv;

	env = ft_env_init(envp);
	if (!env)
	{
		ft_putendl_fd("Failed to initialize environment", 2);
		return (1);
	}

	test_builtins(env);
	ft_env_clear(&env);
	return (0);
}
