/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:45:49 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/09 20:03:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	symbol;
	size_t			length;

	symbol = c;
	length = ft_strlen(s) + 1;
	while (length--)
	{
		if (s[length] == symbol)
			return ((char*)s + length);
	}
	return (NULL);
}
