/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:03:46 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/16 15:02:11 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	value;

	value = n;
	if (value < 0)
	{
		ft_putchar_fd('-', fd);
		value *= -1;
	}
	if (value / 10 != 0)
	{
		ft_putnbr_fd(value / 10, fd);
		ft_putchar_fd(value % 10 + 48, fd);
	}
	else
		ft_putchar_fd(value % 10 + 48, fd);
}
