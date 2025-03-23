#include "minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str[0] || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_list(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(current->name, STDOUT_FILENO);
		if (current->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(current->value, STDOUT_FILENO);
			ft_putchar_fd('\"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		current = current->next;
	}
}

int	ft_export(char **args, t_env *env)
{
	char	*key;
	char	*value;
	int		i;
	int		ret;

	ret = 0;
	if (!args[1])
	{
		print_export_list(env);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			ret = 1;
		}
		else
		{
			key = ft_get_key(args[i]);
			value = ft_get_value(args[i]);
			ft_setenv(key, value, env);
			free(key);
            if (value)
                free(value);
		}
		i++;
	}
	return (ret);
}
