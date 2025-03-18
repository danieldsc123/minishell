/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:02:06 by daniel-da         #+#    #+#             */
/*   Updated: 2025/03/18 00:15:28 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_STRUCT_H
# define EXPANSOR_STRUCT_H

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_expander
{
	char	*input;
	char	*output;
	int		status_code;
	t_env	*env_list;
}	t_expander;

#endif