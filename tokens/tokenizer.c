/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:18:43 by danielda          #+#    #+#             */
/*   Updated: 2025/02/21 17:05:52 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_operator(char *input, t_token **tokens, int *i) //Identifica operadores (|, <, >, <<, >>) e chama get_redirs_token() se necessário.
{
}

void	get_word(char *input, t_token **tokens, int *i) //Captura palavras (comandos, argumentos, arquivos).
{
}

void	get_redirs_token(char *input, t_token **tokens, int *i) //Trata redirecionadores (<, >, <<, >>) corretamente.
{
}
