/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:53:36 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 20:59:08 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*string_init(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		put_error("malloc error", NULL);
	str[0] = '\0';
	return (str);
}

static char	*ft_read(char *file)
{
	char	*map_string;
	char	buffer[1000 + 1];
	char	*str;
	int		fd;
	int		return_value;

	fd = open(file, O_RDONLY);
	return_value = 1;
	map_string = string_init();
	while (return_value)
	{
		return_value = read(fd, buffer, 1000);
		if (return_value < 0)
		{
			free(map_string);
			put_error("read error", NULL);
		}
		buffer[return_value] = '\0';
		str = map_string;
		map_string = ft_strjoin(str, buffer);
		free (str);
		if (!map_string)
			put_error("malloc error", NULL);
	}
	return (map_string);
}

char	**ft_get_file(char *file)
{
	char	*line;
	char	**map;

	line = ft_read(file);
	map = ft_split(line, '\n');
	if (!map)
	{
		free(line);
		put_error("malloc error", NULL);
	}
	free(line);
	return (map);
}
