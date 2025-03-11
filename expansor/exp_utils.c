/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:55:00 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/11 07:10:30 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Verifica se um caractere é válido para um nome de variável.
int	is_valid_var_char(char c, int first)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	if (!first && (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

//Extrai o nome da variável de um trecho da string
char	*get_var_name(char *str)
{
	int		len;
	char	*var_name;

	len = 0;
	if (!is_valid_var_char(str[len], 1))
		return (NULL);
	while (is_valid_var_char(str[len], 0))
		len++;
	var_name = ft_substr(str, 0, len);
	return (var_name);
}

// char	*get_var_name(char *str)
// {
// 	int		len;
// 	char	*var_name;

// 	len = 0;
// 	while (is_valid_var_char(str[len]))
// 		len++;
// 	var_name = ft_substr(str, 0, len);
// 	return (var_name);
// }

//Retorna o tamanho do nome da variável, considerando $VAR_NAME.
int	var_name_len(char *str)
{
	int	len;

	len = 0;
	if (str[len] == '$')
		len++;
	while (is_valid_var_char(str[len], 0))
		len++;
	return (len);
}

//Junta duas strings e libera a memória anterior.
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (new_str);
}

// Junta um caractere a uma string e libera a antiga.
char	*ft_charjoin_free(char *s1, char c)
{
	char	*new_str;
	char	*char_str;

	char_str = ft_calloc(2, sizeof(char));
	char_str[0] = c;
	new_str = ft_strjoin_free(s1, char_str);
	return (new_str);
}
