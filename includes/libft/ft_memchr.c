/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:02:37 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/09 18:54:28 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string_of_bytes;
	unsigned char	value_of_byte;

	string_of_bytes = (unsigned char*)s;
	value_of_byte = c;
	while (n > 0)
	{
		if (*string_of_bytes == value_of_byte)
			return (string_of_bytes);
		string_of_bytes++;
		n--;
	}
	return (NULL);
}
