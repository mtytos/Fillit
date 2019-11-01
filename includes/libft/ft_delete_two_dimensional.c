/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_two_dimensional.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:51:34 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/22 15:15:39 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_two_dimensional(char ***array, size_t length)
{
	size_t		index;

	if (*array)
	{
		index = 0;
		if ((*array)[index])
		{
			while ((*array)[index] && index < length)
			{
				free((*array)[index]);
				(*array)[index++] = NULL;
			}
		}
		free(*array);
		*array = NULL;
	}
}
