/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:20:51 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/09 22:05:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*box1;
	unsigned char	*box2;

	box1 = (unsigned char*)s1;
	box2 = (unsigned char*)s2;
	while ((*box1 != '\0' || *box2 != '\0') && n--)
	{
		if (*box1 != *box2)
			return (*box1 - *box2);
		box1++;
		box2++;
	}
	return (0);
}
