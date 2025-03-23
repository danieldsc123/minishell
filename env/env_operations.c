#include "minishell.h"

char	*ft_getenv(const char *name, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, (char *)name) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void    ft_setenv(const char *name, const char *value, t_env *env)
{
    t_env    *current;
    t_env    *new;

    current = env;
    while (current)
    {
        if (ft_strcmp(current->name, (char *)name) == 0)
        {
            if (current->value)
                free(current->value);
            if (value)
                current->value = ft_strdup((char *)value);
            else
                current->value = NULL;
            return ;
        }
        current = current->next;
    }
    new = ft_env_new((char *)name, (char *)value);
    if (!new)
        return ;
    ft_env_add_back(&env, new);
}

void	ft_unsetenv(const char *name, t_env *env)
{
	t_env	*current;
	t_env	*prev;

	current = env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->name, (char *)name) == 0)
		{
			if (prev)
				prev->next = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

t_env	*ft_env_init(char **envp)
{
	t_env	*env;
	t_env	*new;
	char	*key;
	char	*value;
	int		i;

	env = NULL;
	i = 0;
	while (envp[i])
	{
		key = ft_get_key(envp[i]);
		value = ft_get_value(envp[i]);
		new = ft_env_new(key, value);
		free(key);
		free(value);
		ft_env_add_back(&env, new);
		i++;
	}
	return (env);
}
