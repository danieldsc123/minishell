/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:55:50 by danielda          #+#    #+#             */
/*   Updated: 2025/02/27 22:01:08 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Verificar se um caractere é uma aspa simples ou dupla.
t_bool	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

//Ignorar tudo dentro de aspas e avançar o índice.
void	skip_quotes(char *input, int *i)
{
	char	quote;

	if (!input || !i || !is_quote(input[*i]))
		return ;
	quote = input[*i];
	(*i)++;
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
		(*i)++;
}

//Contar aspas não fechadas na string de entrada.
t_bool	has_unclosed_quotes(char *input)
{
	int		i;
	char	quote;

	i = 0;
	while (input[i])
	{
		if (is_quote(input[i]))
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

//Remove aspas de um token, mantendo o conteúdo interno.
char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	quote;

	if (!str)
		return (NULL);
	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				new_str[j++] = str[i++];
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}
