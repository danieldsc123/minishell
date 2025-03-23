#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **args, t_env *env)
{
	int	status;

	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		exit(0);
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return ;
	}
	status = ft_atoi(args[1]);
	(void)env;
	ft_env_clear(&env);
	exit(status % 256);
}
