/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:54:03 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/09 13:48:56 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				counter;
	unsigned char		*object;
	unsigned char const	*source;
	unsigned char		symbol;

	if (!(dst || src))
		return (0);
	counter = -1;
	object = dst;
	source = src;
	symbol = c;
	while (++counter < n)
	{
		object[counter] = source[counter];
		if (source[counter] == symbol)
			return (&object[counter + 1]);
	}
	return (NULL);
}
