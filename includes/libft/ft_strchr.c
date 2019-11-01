/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:29:47 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/30 22:06:16 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	symbol;

	if (!s)
		return (NULL);
	symbol = c;
	while (*s)
	{
		if (*s == symbol)
			return ((char*)s);
		s++;
	}
	if (symbol == '\0' && *s == symbol)
		return ((char*)s);
	return (NULL);
}
