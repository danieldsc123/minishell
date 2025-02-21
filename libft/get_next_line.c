/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2025/02/09 19:45:54 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rl[1024];
	char		*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	buffer = ft_check_buffer(fd, &rl[fd]);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		rl[fd] = ft_get_temp(bytes_read, buffer, rl[fd]);
		if (ft_strchr(rl[fd], '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!rl[fd] || rl[fd][0] == '\0')))
		return (free(rl[fd]), rl[fd] = NULL);
	line = ft_extract_line(rl[fd]);
	temp = ft_strdup(rl[fd] + ft_strlen(line));
	free(rl[fd]);
	rl[fd] = temp;
	return (line);
}

char	*ft_extract_line(char *rl)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (rl[i] && rl[i] != '\n')
		i++;
	if (rl[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = rl[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_check_buffer(int fd, char **rl)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (*rl == NULL)
		*rl = ft_strdup("");
	return (buffer);
}

char	*ft_get_temp(int bytes_read, char *buffer, char *rl)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = ft_strjoin(rl, buffer);
	free(rl);
	return (temp);
}
