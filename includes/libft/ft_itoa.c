/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:54:19 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/14 11:08:37 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_count(long long value, int minus)
{
	size_t	count;

	if (minus == 0)
		count = 1;
	else
		count = 2;
	while (value / 10 > 0)
	{
		count++;
		value /= 10;
	}
	return (count);
}

static void		ft_putdigit(char *string, long long value, size_t length)
{
	while (value / 10 > 0)
	{
		string[length-- - 1] = value % 10 + 48;
		value /= 10;
	}
	string[length - 1] = value % 10 + 48;
}

char			*ft_itoa(int n)
{
	int			minus;
	size_t		length;
	long long	value;
	char		*string_of_digit;

	minus = 0;
	value = n;
	if (n < 0)
	{
		minus = -1;
		value = value * minus;
	}
	length = find_count(value, minus);
	string_of_digit = ft_strnew(length);
	if (!string_of_digit)
		return (NULL);
	if (minus < 0)
	{
		*string_of_digit = '-';
		length--;
		minus = 1;
	}
	ft_putdigit(string_of_digit + minus, value, length);
	return (string_of_digit);
}
