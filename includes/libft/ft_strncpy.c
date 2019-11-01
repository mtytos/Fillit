/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:41:30 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/16 13:41:15 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	length;

	length = ft_strlen(src);
	if (length < len)
	{
		ft_memcpy(dst, src, length);
		ft_bzero(&dst[length], len - length);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
