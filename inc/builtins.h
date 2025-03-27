/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:23:02 by agbarbos          #+#    #+#             */
/*   Updated: 2025/03/27 00:54:08 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// Funções de gestão de variáveis de ambiental
t_env	*ft_env_new(char *name, char *value);
void	ft_env_add_back(t_env **env, t_env *new);
void	ft_env_clear(t_env **env);
char	*ft_getenv(const char *name, t_env *env);
void	ft_setenv(const char *name, const char *value, t_env *env);
void	ft_unsetenv(const char *name, t_env *env);
char	*ft_get_key(char *str);
char	*ft_get_value(char *str);
t_env	*ft_env_init(char **envp);

// Funções builtins
int		ft_echo(char **args);
int		ft_cd(char **args, t_env *env);
int		ft_pwd(void);
int		ft_export(char **args, t_env *env);
int		ft_unset(char **args, t_env *env);
int		ft_env(t_env *env);
void	ft_exit(char **args, t_env *env);

#endif
