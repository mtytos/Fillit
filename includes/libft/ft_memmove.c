/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:26:19 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/09 18:46:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*object;
	unsigned char const	*source;

	if (!(dst || src))
		return (0);
	object = dst;
	source = src;
	if (source > object)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len-- > 0)
			object[len] = source[len];
	}
	return (object);
}
