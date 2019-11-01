/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:51:24 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/21 22:02:11 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

void	no_valid(void)
{
	write(1, "error\n", 6);
	exit(11);
}

void	memory_allocation_error(void)
{
	write(1, "error\n", 6);
	exit(13);
}
