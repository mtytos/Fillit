/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:36:42 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/30 18:12:41 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	length;

	length = size + 1;
	if (length < size)
		return (NULL);
	if (!(string = (char*)ft_memalloc(length)))
		return (NULL);
	return (string);
}
