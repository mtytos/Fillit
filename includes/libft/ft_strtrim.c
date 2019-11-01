/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:11:25 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/12 18:47:54 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*copy_of_string;
	size_t	length;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	length = ft_strlen(s);
	if (length)
	{
		while (ft_iswhitespace(s[length - 1]))
			length--;
	}
	copy_of_string = ft_strnew(length);
	if (!copy_of_string)
		return (NULL);
	ft_strncat(copy_of_string, s, length);
	return (copy_of_string);
}
