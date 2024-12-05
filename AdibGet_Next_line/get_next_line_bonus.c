/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:08:47 by yadib             #+#    #+#             */
/*   Updated: 2024/12/02 15:13:33 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	index;

	if (s == NULL)
		return (-1);
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)(c))
			return (index);
		index++;
	}
	if ((char)c == '\0')
		return (index);
	return (-1);
}

char	*get_a_line(char *content, char **rest, int index)
{
	char	*line;

	line = NULL;
	if (index >= 0)
	{
		line = malloc((size_t)index + 2);
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, content, (index + 2));
		*rest = ft_strdup(&content[index + 1]);
	}
	else if (content != NULL)
	{
		line = ft_strdup(content);
		*rest = NULL;
	}
	return (line);
}

int	read_lines_end_index(char **content, int fd)
{
	int		index;
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*content);
			*content = NULL;
		}
		buffer[bytes_read] = '\0';
		*content = ft_strjoin(*content, buffer);
		index = ft_strchr(*content, '\n');
		if (index >= 0)
			return (free(buffer), index);
	}
	return (free(buffer), -1);
}

char	check_condition(int fd, char **rest)
{
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
	{
		if (read(fd, 0, 0) == 0 && rest[fd])
		{
			free(rest[fd]);
			rest[fd] = NULL;
		}
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	char		*content;
	int			index;

	if (check_condition(fd, rest) == 0)
		return (0);
	index = -1;
	content = NULL;
	line = NULL;
	content = ft_strjoin(content, rest[fd]);
	index = ft_strchr(content, '\n');
	free(rest[fd]);
	if (index == -1)
		index = read_lines_end_index(&content, fd);
	if (content != NULL)
	{
		line = get_a_line(content, &(rest[fd]), index);
		free(content);
	}
	return (line);
}
