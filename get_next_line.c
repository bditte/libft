/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:33:36 by bditte            #+#    #+#             */
/*   Updated: 2021/02/03 10:55:28 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	verify(char **str, int ret)
{
	if (!ret)
	{
		free(*str);
		*str = 0;
	}
}

int		get_next_line(int fd, char **line)
{
	static char *str[256];
	char		*buffer;
	int			ret;
	int			read_value;
	char		c;

	if (!line || BUFFER_SIZE <= 0 || (read(fd, &c, 0) == -1)
		|| (!str[fd] && (!(str[fd] = malloc(1))
		|| (*str[fd] = 0)))
		|| !(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strchr_gnl(str[fd], '\n')
		&& (read_value = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_value] = 0;
		str[fd] = ft_strjoin_gnl(&str[fd], buffer);
	}
	*line = ft_newline(str[fd]);
	ret = ft_strchr_gnl(str[fd], '\n');
	if (!ft_strcut(&str[fd]))
		return (-1);
	free(buffer);
	verify(&str[fd], ret);
	return (ret);
}
