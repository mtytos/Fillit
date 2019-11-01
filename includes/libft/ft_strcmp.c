/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:48:40 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/12 17:11:36 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *box1;
	unsigned char *box2;

	box1 = (unsigned char*)s1;
	box2 = (unsigned char*)s2;
	while (*box1 != '\0' || *box2 != '\0')
	{
		if (*box1 != *box2)
			return (*box1 - *box2);
		box1++;
		box2++;
	}
	return (0);
}
