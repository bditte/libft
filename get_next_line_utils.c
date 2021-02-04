/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:19:14 by bditte            #+#    #+#             */
/*   Updated: 2021/02/04 14:25:52 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strcut(char **str)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	while ((*str)[i + j])
		j++;
	if (!(res = malloc(sizeof(char) * j + 1)))
		return (-1);
	res[j] = 0;
	while (j--)
		res[j] = (*str)[i + j + 1];
	free(*str);
	*str = res;
	return (1);
}

char	*ft_newline(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (!(tmp = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		*(tmp++) = str[i++];
	*(tmp) = '\0';
	tmp -= i;
	return (tmp);
}

size_t	ft_strlen_gnl(char *src)
{
	size_t len;

	len = 0;
	while (src[len] && src[len] != 0)
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*dst;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen_gnl(*s1) + ft_strlen_gnl(s2) + 1))))
		return (NULL);
	while ((*s1)[s1len])
	{
		*dst++ = (*s1)[s1len];
		s1len++;
	}
	while (s2[s2len])
	{
		*dst++ = s2[s2len];
		s2len++;
	}
	free(*s1);
	*dst = 0;
	return (dst - s1len - s2len);
}

int		ft_strchr_gnl(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
