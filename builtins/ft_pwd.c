#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, 4096))
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (0);
	}
	ft_putstr_fd("minishell: pwd: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}
