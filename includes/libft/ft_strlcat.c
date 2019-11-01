/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:41:52 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/19 20:54:54 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		length_dst;
	size_t		length_src;
	char		*pointer_to_s1;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (size <= length_dst)
		return (length_src + size);
	else if (length_dst + 1 < size)
	{
		pointer_to_s1 = ft_strchr(dst, '\0');
		ft_memccpy(pointer_to_s1, src, '\0', size - length_dst - 1);
		if (size <= length_dst + length_src)
			dst[size - 1] = '\0';
	}
	return (length_dst + length_src);
}
