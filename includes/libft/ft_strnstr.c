/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:40:46 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/11 16:55:33 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*box_for_string;
	size_t	length_needle;

	if (*needle == '\0')
		return ((char*)haystack);
	box_for_string = ft_strdup(haystack);
	if (!box_for_string)
		return (NULL);
	if (len < ft_strlen(box_for_string))
		box_for_string[len] = '\0';
	length_needle = ft_strlen(needle);
	while (*box_for_string)
	{
		if (ft_strncmp(box_for_string, needle, length_needle) == 0)
			return ((char*)haystack);
		box_for_string++;
		haystack++;
	}
	return (NULL);
}
