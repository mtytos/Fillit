/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:11 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/25 17:38:04 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	index;

	if (!s || (start + len > ft_strlen(s)))
		return (NULL);
	new_string = ft_strnew(len);
	if (!new_string)
		return (NULL);
	index = 0;
	while (index < len)
	{
		new_string[index] = s[start];
		index++;
		start++;
	}
	return (new_string);
}
