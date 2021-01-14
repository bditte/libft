/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:42:26 by bditte            #+#    #+#             */
/*   Updated: 2021/01/15 00:09:03 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (*us1 || *us2)
		if (*us1++ != *us2++)
			return (*--us1 - *--us2);
	return (0);
}
