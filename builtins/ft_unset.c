#include "minishell.h"

int	ft_unset(char **args, t_env *env)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			ret = 1;
		}
		else
			ft_unsetenv(args[i], env);
		i++;
	}
	return (ret);
}
