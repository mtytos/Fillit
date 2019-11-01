/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:32:37 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/25 17:58:25 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*filler;

	counter = 0;
	filler = b;
	while (counter < len)
	{
		filler[counter] = (unsigned char)c;
		counter++;
	}
	return (filler);
}
