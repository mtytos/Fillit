/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:58:29 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/26 20:18:37 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	buffer = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!buffer)
		return (NULL);
	ft_strcat(ft_strcpy(buffer, s1), s2);
	return (buffer);
}
