/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:42:32 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/16 17:23:58 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	found_count_of_string(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	if (*s != c && *s++ != '\0')
		counter++;
	while (*s != '\0')
	{
		if (*s != c && *(s - 1) == c)
			counter++;
		s++;
	}
	return (counter);
}

static void		ft_delete_array(char **array, size_t length)
{
	while (length--)
	{
		ft_strdel(&array[length - 1]);
		array[length - 1] = NULL;
	}
	free(array);
	array = NULL;
}

static char		**dynamic_memalloc(char const *s, char c, size_t len)
{
	size_t	index;
	size_t	counter_chars;
	char	**new_array;

	new_array = (char**)malloc(sizeof(char*) * (len + 1));
	if (!new_array)
		return (NULL);
	index = -1;
	while (++index < len)
	{
		counter_chars = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			counter_chars++;
			s++;
		}
		if (!(new_array[index] = ft_strnew(counter_chars)))
		{
			ft_delete_array(new_array, index + 1);
			return (NULL);
		}
	}
	return (new_array);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	count_of_string;
	size_t	number;
	char	**splited_string;

	if (!s)
		return (NULL);
	count_of_string = found_count_of_string(s, c);
	if (!(splited_string = dynamic_memalloc(s, c, count_of_string)))
		return (NULL);
	index = -1;
	while (++index < count_of_string)
	{
		while (*s == c)
			s++;
		number = 0;
		while (*s != c && *s != '\0')
		{
			splited_string[index][number] = *s++;
			number++;
		}
	}
	splited_string[index] = NULL;
	return (splited_string);
}
