/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:44:13 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/11 21:46:54 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*pointer_to_new_string;

	if (!s)
		return (NULL);
	pointer_to_new_string = ft_strnew(ft_strlen(s));
	if (!pointer_to_new_string)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		pointer_to_new_string[index] = f(index, s[index]);
		index++;
	}
	return (pointer_to_new_string);
}
