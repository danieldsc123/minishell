#include "minishell.h"

int	ft_cd(char **args, t_env *env)
{
	char	*path;
	char	cwd[4096];

	if (!args[1])
	{
		path = ft_getenv("HOME", env);
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	if (getcwd(cwd, 4096))
		ft_setenv("PWD", cwd, env);
	return (0);
}
