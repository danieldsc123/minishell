/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:10:00 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/09 17:41:57 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Remove aspas ao redor das palavras expandidas corretamente.
char	*remove_extra_quotes(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			i++;
		else
			new_str = ft_charjoin_free(new_str, str[i++]);
	}
	free(str);
	return (new_str);
}
